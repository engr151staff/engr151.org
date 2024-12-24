# ENGR 151 F24 Project 4

## Description
This project seeks to teach students about object-oriented programming and inheritance in C++, using the behavior of radioactive nuclei as a backdrop to motivate the program. Students must first implement a class to model the behavior of a generic population of radionuclei, then two derived classes to model the behavior of populations of the particular radionuclides Technetium-99 and Molybdenum-99, and finally use their classes to write a simulation of a Technetium Generator. 

## Contents
- `archive/`: Old versions of files I didnt want to delete
- `sol/`: Contains solution to the project, correct outputs, and a Makefile for easy compilation
- `starter/`: Contains the starter code for students
- `engr_151_f24_p4.pdf`: PDF copy of project specification
- `engr_151_f24_p4.zip`: Zip archive of LaTeX source of project specification

## Compilation & Execution
Switch into sol/ directory
```bash
cd sol/
```
To compile and run testRadionuc.cpp to test radionuc.hpp:
```bash
make testradionuc.exe
./testradionuc.exe
```
To compile and run tcGenerator.cpp to simulation Technetium Generator
```bash
make tcgen.exe
./tcgen.exe POPULATION_SIZE SIMULATION_LENGTH
```

## Known Problems
This semester, we found that students with functionally identical implementation could achieve different results, based on whether they were running on Mac or on WSL. We have determined this is because Mac and WSL are producing a different sequence of random numbers for the same seed, but we have not determined why that is, or how it could be fixed. This does not interfere with the students' results on autograder, i.e. a correct implementation written on either Mac or WSL will score the same 100% on the autograder. However, it did for a time disrupt the students' ability to locally check their results, as we originally only published correct outputs generated on a WSL machine. To remedy this, we decided it was simplest to additionally publish the correct outputs generated on a Mac. However, for a smoother run of this project, the root cause of this issue should be identified and fixed.