//
//  config.hpp
//  SimCityProject
//
//  Created by JonTrelle Norgaisse on 6/24/25.
//

#ifndef config_hpp
#define config_hpp
#include <string>
#include <stdio.h>

class ConfigReader {
public:
    ConfigReader(const std::string& filename); //Constructor that takes the name of the config file
    
    std::string getRegionFile() const;      //returns region layout file name
    int getMaxTimeSteps() const;            // returns max time steps
    int getRefreshRate() const;             //returns refresh rate
    
private:
    std::string regionFile;
    int maxTimeSteps;
    int refreshRate;
    
    void readConfigFile(const std::string& filename);   //helper functino to read the file name
    
};

#endif /* config_hpp */
