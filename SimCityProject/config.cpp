//
//  config.cpp
//  SimCityProject
//
//  Created by JonTrelle Norgaisse on 6/24/25.
//

#include "config.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>


//Constructor: will automatically read the files when the ConfigReader object is made
ConfigReader::ConfigReader(const std::string& filename) {
    readConfigFile(filename);
}

//function: to read the config file and stores the values
void ConfigReader::readConfigFile(const std::string &filename) {
    std::fstream file(filename);
    
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open config file.");
    }
    
    //Read 3 lines from the file
    std::getline(file, regionFile);        //Line1: Region layout file name
    file >> maxTimeSteps;                  //Line2: Max time steps (as a number)
    file >> refreshRate;                   //Line3: Refresh rate (as a number)
}

//Return the region layout file name
std::string ConfigReader::getRegionFile() const {
    return regionFile;
}

//Return the max time steps
int ConfigReader::getMaxTimeSteps() const {
    return maxTimeSteps;
}

//Return the refresh rate
int ConfigReader::getRefreshRate() const {
    return refreshRate;
}
