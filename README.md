==================================================
SIMCITY SIMULATION PROJECT - README
==================================================

Group Members:
--------------
- Wuraola Smith
- Jontrelle Norgaisse
- Gerald Iverson

--------------------------------------------------

Compilation Instructions:
-------------------------
To compile the program, open a terminal and navigate to the SimCityProject directory.

Run the following command:

    g++ -std=c++17 -o simcity main.cpp config.cpp region.cpp simulation.cpp

This compiles the program and creates an executable named `simcity`.

--------------------------------------------------

Execution Instructions:
-----------------------
To run the simulation:

    ./simcity

You will be prompted to enter the configuration file name. For example:

    Enter the name of the configuration file: data/config2.txt

This file must contain:

Line 1: The name of the region layout file (e.g. `data/region2.csv`)  
Line 2: The maximum number of time steps (e.g. `20`)  
Line 3: The refresh rate (e.g. `5`)

--------------------------------------------------

Example Configuration File (config2.txt):
----------------------------------------
data/region2.csv  
20  
5  

--------------------------------------------------

Expected Output:
----------------
- The initial region layout (time step 0)
- Updates every N steps (based on refresh rate)
- Worker/good availability per step
- Final region statistics:
    - Population totals (R, C, I)
    - Pollution totals
- Optional: Detailed stats on a user-specified region

--------------------------------------------------

Required Files:
---------------
Make sure the following files are present:
- main.cpp
- config.cpp / config.hpp
- region.cpp / region.hpp
- simulation.cpp / simulation.hpp
- data/config2.txt
- data/region2.csv

--------------------------------------------------

Dependencies:
-------------
- A C++17 compatible compiler (e.g. `g++`, `clang++`)
- Terminal or shell to compile and run

--------------------------------------------------

Notes:
------
- File paths are case-sensitive.
- Do not hardcode file names in your program.
- Use meaningful commit messages in your version control.

--------------------------------------------------
