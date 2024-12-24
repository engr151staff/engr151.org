#include "molybdenum.hpp"
#include "technetium.hpp"
#include <iostream>

using namespace std;

void processCommandLine(int argc, char *argv[], int &initMoPop, int &Tf);
int technetiumGenerator(const int moPopSize, const int Tf);

int main(int argc, char *argv[]) {
    // Seed RNG
    srand(0);
    // Initialize user-controller simulation parameters
    int initMoPop;
    int Tf;
    // Set values of user-controller sim parameters and error check
    processCommandLine(argc, argv, initMoPop, Tf);
    // Run simulation for selected values
    int tcCollected = technetiumGenerator(initMoPop, Tf);
    // Print out results
    cout << "Initial Mo99 population: " << initMoPop << endl;
    cout << "Simulation length: " << Tf << " hours" << endl;
    cout << "Total Tc99 harvested: " << tcCollected << endl;
    // Return 0 on successful program execution
    return 0;
}

void processCommandLine(int argc, char *argv[], int &initMoPop, int &Tf) {
    // ./<exe> <initial Mo99 pop> <Tf>
    if (argc != 3) {
        std::cout << "Incorrect number of command line arguments." << std::endl;
        exit(1);
    } else {
        // Read in candidate values
        initMoPop = atoi(argv[1]);
        Tf = atoi(argv[2]);
        // Check for errors
        if (initMoPop < 1e3 || initMoPop > 1e7) {
            std::cout << "Invalid initial Mo-99 population." << std::endl;
            exit(1);
        } else if (Tf < 10 || Tf > 500) {
            std::cout << "Invalid simulation length." << std::endl;
            exit(1);
        }
    }
}

int technetiumGenerator(const int moPopSize, const int Tf) {
    // Create initial population of Mo99 nuclei
    Mo99 mo(moPopSize);
    // Create (zero) initial population of Tc99 nuclei
    Tc99 tc(0);
    // Initialize simulation variables
    const double dt = 1; // Time step for sim (hours)
    int t = 0;           // Current time in simulation
    // Create variable to track Tc harvested
    int tcCollected = 0;
    // Run simulation
    cout << "t\tMo99\tTc99" << endl;
    while (t <= Tf) {
        // Print out current populations
        cout << t << "\t" << mo.Count() << "\t" << tc.Count() << endl;
        // Decay Mo99 population and add to Tc99 population
        int numDecayed = mo.Decay(dt);
        tc += numDecayed;
        // Decay Tc99 population
        tc.Decay(dt);
        // Check if Tc population is above threshold
        if (tc.Count() > 10000) {
            // Harvest Tc
            tcCollected += tc.Count();
            // Zero population
            tc.Zero();
        }
        // Advance sim time
        t++;
    }
    // Return total population of Tc harvested
    return tcCollected;
}