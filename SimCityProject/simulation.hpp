//
//  simulation.hpp
//  SimCityProject
//
//  Created by JonTrelle Norgaisse on 6/24/25.
//

#ifndef simulation_hpp
#define simulation_hpp

#include <stdio.h>
#include "region.hpp"


//Returns true if any part of the city changed during this step
bool simulateStep(Region& city, int currentTime);


#endif /* simulation_hpp */
