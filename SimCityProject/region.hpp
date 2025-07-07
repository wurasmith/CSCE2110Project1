//
//  region.hpp
//  SimCityProject
//
//  Created by JonTrelle Norgaisse on 6/24/25.
//

#ifndef region_hpp
#define region_hpp

#include <stdio.h>
#include <vector>
#include <string>

class Region {
public:
    //Constructor: takes the file name of the region layout and loads it
    Region(const std::string& filename);
    
    //Getter for the width of the region (number of columns)
    int getWidth() const;
    
    //Getter for the height of the region (number of rows)
    int getHeight() const;
    
    //Returns the value (zone type) at a specific row and column
    char getCell(int row, int col) const;
    
    //Prints the entire region grid to the console (for testing)
    void printRegion() const;
    
    // direct grid update
    void updateCellDirectly(int row, int col, char value);
    
private:
    //2D grid that stores the map as characters like 'R', 'C', 'I'
    std::vector<std::vector<char>> grid;
    
    // Dimensions of the grid
    int width;
    int height;
    
    //Reads the CSV file and fills the grid
    void loadRegionFile(const std::string& filname);
    
   
    
};

#endif /* region_hpp */
