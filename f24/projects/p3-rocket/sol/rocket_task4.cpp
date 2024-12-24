#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

const double dt = 0.001;
const double r_earth = 6356.0;
const double CD = 0.5;
const double A = M_PI * (6.6e-3) * (6.6e-3) / 4.0;

double vesc2(double g, double h);
double grav(double height);
double air_density(double h);
double drag(double height, double v);
double calc_height(double T, double ve, double M, double M_p);

int main() {
    cout.precision(3);

    double T, ve, M_p;
    ifstream input("init_opt.txt");
    input >> T >> ve >> M_p;
    input.close();

    double min_fuel_mass = 0;
    double max_fuel_mass = T / grav(0) - M_p;
    double rocket_mass = max_fuel_mass + M_p - 0.1;
    double max_height = calc_height(T, ve, rocket_mass, M_p);

    if (max_height < 2000) {
        cout << "Rocket too heavy" << endl;
        return 1;
    }

    while (min_fuel_mass < max_fuel_mass) {
        double fuel_mass = (min_fuel_mass + max_fuel_mass) / 2.0;
        double height = calc_height(T, ve, fuel_mass + M_p, M_p);
        if (abs(height - 2000) <= 5) {
            cout << fuel_mass << endl;
            return 0;
        } else if (height < 2000) {
            min_fuel_mass = fuel_mass;
        } else {
            max_fuel_mass = fuel_mass;
        }
    }
}

double calc_height(double T, double ve, double M, double M_p) {
    double v = 0, vold;
    double h = 0;
    while (v > 0.0 || h == 0.0) {
        // Get gravity for this cycle
        double g = grav(h);
        // Check escape velocity
        if (v * v > vesc2(g, h)) {
            cout << "Escape velocity reached" << endl;
            return 4000;
        }
        // Save velocity before we update it
        vold = v;
        // update velocity
        v += dt * (T / M - g - drag(h, v) / M);
        // If we have fuel left then jettison
        if (M > M_p) {
            M = M - T * dt / ve;
        }
        // otherwise stop thrusting and constant mass
        else {
            T = 0.0;
            M = M_p;
        }

        h += vold * dt;
    }

    return h;
}

double grav(double h) { return 3.962e5 / (h + r_earth) / (h + r_earth); }

double vesc2(double g, double h) { return (2 * g * (h + r_earth)); }

// Returns air density at h kilometers, in kg / km^3
double air_density(double h) { return 1.225e6 * exp(-h / 9); }

double drag(double h, double v) {
    return 0.5 * air_density(h) * CD * A * v * v;
}