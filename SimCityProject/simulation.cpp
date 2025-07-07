//
//  simulation.cpp
//  SimCityProject
//
//  Created by JonTrelle Norgaisse on 6/24/25.
//

#include "simulation.hpp"
#include <iostream>



// Simulates one time step of the simulation and returns true if any changes occurred
bool simulateStep(Region& city, int currentTime) {
    bool changed = false;
    int rows = city.getHeight();
    int cols = city.getWidth();

    // Make a copy of the grid
    std::vector<std::vector<char>> nextState(rows, std::vector<char>(cols));

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            nextState[r][c] = city.getCell(r, c);
        }
    }

    // Loop through each cell
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            char current = city.getCell(r, c);

            int nearbyR = 0; // Residential level zones ('1' - '5')
            int nearbyC = 0; // Commercial zones
            int nearbyI = 0; // Industrial zones
            int nearbyHighR = 0; // Residential level 2+ (for industrial)

            // Check 4 neighbors: up, down, left, right
            if (r > 0) {
                char up = city.getCell(r - 1, c);
                if (up == 'C') nearbyC++;
                if (up == 'I') nearbyI++;
                if (up >= '1' && up <= '5') nearbyR++;
                if (up >= '2') nearbyHighR++;
            }
            if (r < rows - 1) {
                char down = city.getCell(r + 1, c);
                if (down == 'C') nearbyC++;
                if (down == 'I') nearbyI++;
                if (down >= '1' && down <= '5') nearbyR++;
                if (down >= '2') nearbyHighR++;
            }
            if (c > 0) {
                char left = city.getCell(r, c - 1);
                if (left == 'C') nearbyC++;
                if (left == 'I') nearbyI++;
                if (left >= '1' && left <= '5') nearbyR++;
                if (left >= '2') nearbyHighR++;
            }
            if (c < cols - 1) {
                char right = city.getCell(r, c + 1);
                if (right == 'C') nearbyC++;
                if (right == 'I') nearbyI++;
                if (right >= '1' && right <= '5') nearbyR++;
                if (right >= '2') nearbyHighR++;
            }

            // --- Residential Growth ---
            if (current == 'R') {
                if (nearbyC + nearbyI >= 1) {
                    nextState[r][c] = '1';
                    changed = true;
                }
            } else if (current >= '1' && current < '5') {
                nextState[r][c] = current + 1; // Level up
                changed = true;
            }

            // --- Commercial Growth ---
            if (current == 'C') {
                if (nearbyR >= 1) {
                    nextState[r][c] = '1';
                    changed = true;
                }
            } else if (current >= '1' && current < '5') {
                // If it's already a number, leave as-is unless leveling up from C
                char below = city.getCell(r, c);
                if (below == '1' || below == '2' || below == '3' || below == '4') {
                    nextState[r][c] = below + 1;
                    changed = true;
                }
            }

            // --- Industrial Growth ---
            if (current == 'I') {
                if (nearbyHighR >= 2) {
                    nextState[r][c] = '1';
                    changed = true;
                }
            } else if (current >= '1' && current < '5') {
                char below = city.getCell(r, c);
                if (below == '1' || below == '2' || below == '3' || below == '4') {
                    nextState[r][c] = below + 1;
                    changed = true;
                }
            }
        }
    }

    // Apply the new state back to the city map
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (city.getCell(r, c) != nextState[r][c]) {
                city.updateCellDirectly(r, c, nextState[r][c]);
            }
        }
    }

    return changed;
}
