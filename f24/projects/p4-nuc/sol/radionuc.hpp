#pragma once
#include <cmath>
#include <iostream>

// TODO: Declare and implement radioNuclide class
class radioNuclide {
  private:
    // Probability a given nucleus decays in 1 second
    double lambda;
    // Number of nuclei in the population
    int popSize;

  public:
    // Default constructor -- sets lambda to 0 and popSize to 1
    radioNuclide();
    // Custom constructor
    radioNuclide(const double lambdaIn, const int popSizeIn);
    // Returns current population size
    int Count();
    // Decays the population over time interval dt
    int Decay(const double dt);
    // Adds to population
    void Add(const int num);
    // Zeros population
    void Zero();
    // Adds to population
    void operator+=(const int num);
};

radioNuclide::radioNuclide() : lambda(0), popSize(1) {}

radioNuclide::radioNuclide(const double lambdaIn, const int popSizeIn)
    : lambda(lambdaIn), popSize(popSizeIn) {}

int radioNuclide::Count() { return popSize; }

int radioNuclide::Decay(const double dt) {
    int numDecayed = 0;
    // Compute probability of decay in time interval
    double probDecay = dt * lambda;
    // Loop through population
    for (int i = 0; i < popSize; ++i) {
        // Generate random number between 0 and 1
        double randNum = static_cast<double>(rand()) / RAND_MAX;
        // Compare against probability of decay
        if (randNum < probDecay) {
            // Count up all nuclei that decay
            ++numDecayed;
        }
    }
    // Reduce population
    popSize -= numDecayed;
    // Return number of nuclei that decayed
    return numDecayed;
}

void radioNuclide::Add(const int num) { popSize += num; }

void radioNuclide::Zero() { popSize = 0; }

void radioNuclide::operator+=(const int num) { radioNuclide::Add(num); }