#include <fstream>
#include <iostream>
#include <cmath>
#include <cassert>
#include "radionuc.hpp"
#include "molybdenum.hpp"
#include "technetium.hpp"

using namespace std;

void testDefaultCtor();
void testCustomCtor();
void testDecay();
void testAdd();
void testZero();
void testOperatorPlusEquals();
void testEstimateHalfLife();

int main() {
    // Seed RNG
    srand(0);
    // Run all tests
    testDefaultCtor();
    testCustomCtor();
    testDecay();
    testAdd();
    testZero();
    testOperatorPlusEquals();
    testEstimateHalfLife();
    // Return 0 on successful program completion
    return 0;
}

void testDefaultCtor()
{
    // Use default constructor to create a radionuc instance
    radioNuclide myRadionuc;
    // Check that the population size is 1 as expected
    assert(myRadionuc.Count() == 1);
}

void testCustomCtor()
{
    // Use custom constructor to create a radionuc instance
    radioNuclide myRadionuc(0.5,100);
    // Check that the population size is 100 as expected
    assert(myRadionuc.Count() == 100);
}

void testDecay()
{
    // Open a file to write test results to
    ofstream fout("testDecayOut.txt");

    const int N0 = 10000000; // Initial population size
    const double lambda = log(2.0) / (109.771 / 60.0); // Rate of decay
    const double tmax = 20; // End time of simulation (hours)
    const double dt = 0.01; // Time step of simulation (hours)
    double t = 0; // Current time of simulation (hours)
    radioNuclide F18(lambda,N0); // Construct population of Fluorine18 nuclei

    fout << "t\tF18" << endl; // Print column headers
    while (t < tmax + dt)
    { // Loop while within defined simulation time
        fout << t << "\t" << F18.Count() << endl; // Print time and population size
        F18.Decay(dt); // Decay the population
        t += dt; // Advance simulation time
    }
}

void testAdd()
{
    // Using default constructor -- popSize is now 1
    radioNuclide myRadionuc;
    // Use add to increase popSize
    myRadionuc.Add(100);
    // Check that popSize is 101 as expected
    assert(myRadionuc.Count() == 101);
}

void testZero()
{
    // Using default constructor -- popSize is now 1
    radioNuclide myRadionuc;
    // Use zero to clear population
    myRadionuc.Zero();
    // Check that population is 0 as expected
    assert(myRadionuc.Count() == 0);
}

void testOperatorPlusEquals()
{
    // Using default constructor -- popSize is now 1
    radioNuclide myRadionuc;
    // Use += to increase population
    myRadionuc += 200;
    // Check that population is 201 as expected
    assert(myRadionuc.Count() == 201);
}

void testEstimateHalfLife()
{
    // Create lamda variable
    double lambda = log(2.0) / 60;
    // Calculate expected half life
    int expectedHL = static_cast<int>(log(2.0) / lambda);
    // Create radionuc instance with lambda
    radioNuclide myRadionuc(lambda, 100000);
    // Approximate the half life of the radionuc through simulation
    int simHL = myRadionuc.EstimateHalfLife();
    // Check that sim matches expectation to within two hours
    assert(abs(simHL - expectedHL) <= 2);
}