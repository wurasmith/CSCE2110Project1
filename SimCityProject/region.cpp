//
//  region.cpp
//  SimCityProject
//
//  Created by JonTrelle Norgaisse on 6/24/25.
//

#include "region.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>



// Constructor: calls the private function to load the region layout
Region::Region(const std::string& filename) {
    loadRegionFile(filename);
}

// This function reads the region layout from a CSV file
void Region::loadRegionFile(const std::string& filename) {
    std::ifstream file(filename);   //try to open the file
    
    if (!file.is_open()) {
        //If the file fails to open, throw an error
        throw std::runtime_error("Error: Could not open region layout file.");
    }
    
    std::string line;
    while (std::getline(file, line)) {
        std::vector<char> row;          //This will store one row of the grid
        std::stringstream ss(line);     //Convert the line into a stream for splitting
        std::string cell;
        
        //Split the line by commas
        while (std::getline(ss, cell, ',')) {
            if (!cell.empty()) {
                row.push_back(cell[0]); //Adds the first character (R, C, I, etc.) tothe row
            }
        }
        
        if (!row.empty()) {
            grid.push_back(row);        //Adds the row to the grid
        }
    }
    
    //Set the dimensions of the region
    height = grid.size();
    width = (height > 0) ? grid[0].size() : 0;
}

//Returns the number of columns in the region
int Region::getWidth() const {
    return width;
}

//Return the number of rows in the region
int Region::getHeight() const {
    return height;
}

//Returns the value at a spefic cell in the grud
char Region::getCell(int row, int col) const {
    //Check if the row and col are within bounds
    if (row >= 0 && row < height && col >= 0 && col < width) {
        return grid[row][col];
    }
    return '?'; //Return a placeholder if the postition is invalid
}

//Print the current grid to the screen (for testing/debbuging)
void Region::printRegion() const {
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << ' '; //Print each cell followed by a space
        }
        std::cout << std::endl; //Newline after each row
    }
}


void Region::updateCellDirectly(int row, int col, char value) {
    if (row >= 0 && row < height && col >= 0 && col < width) {
        grid[row][col] = value;
    }
}


