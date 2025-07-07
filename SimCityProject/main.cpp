//
//  main.cpp
//  SimCityProject
//
//  Created by JonTrelle Norgaisse on 6/24/25.
//
#include "simulation.hpp"
#include "region.hpp"
#include "config.hpp"
#include <iostream>

int main() {
    std::string configFileName;
    std::cout << "Enter the name of the configuration file:" << std::endl;
    std::cin >> configFileName;
    
    try {
        
        //Configuration
        ConfigReader config(configFileName);
        
        //Use the value
        std::string regionLayoutFile = config.getRegionFile();
        int maxTimeSteps= config.getMaxTimeSteps();
        int refreshRate = config.getRefreshRate();
        
        //Debug output (remove late)
        std::cout << "Region layout file: " << regionLayoutFile << std::endl;
        std::cout << "Max time steps: " << maxTimeSteps << std::endl;
        std::cout << "Refresh rate: " << refreshRate << std::endl;
        
        
        //Region
        Region city(regionLayoutFile);      //load map into a 2D grid
        
        
        //Simulation ends early if no change
        int time = 0;
        bool changed = true;
        
        while (time <= maxTimeSteps && changed) {
            changed = simulateStep(city, time);
            
            //Show region state based on the refresh rate
            if (time % refreshRate == 0) {
                std::cout << "Time step: " << time << "\n";
                city.printRegion();         //Show current state of the city
            }
        }
        
        
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1; //exit with error
    }
    

    return 0;
}

