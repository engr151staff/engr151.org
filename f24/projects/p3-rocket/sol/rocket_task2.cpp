#include <fstream>
#include <iostream>

using namespace std;

double dt = 0.001;
double r_earth = 6356.0;

double grav(double h);
double vesc2(double g, double h);

int main() {
    cout.precision(3);

    double T, ve, M, M_p;
    ifstream input("init.txt");
    input >> T >> ve >> M >> M_p;
    input.close();

    double v = 0, vold;
    double h = 0;
    while (v > 0.0 || h == 0.0) {
        // Get gravity for this cycle
        double g = grav(h);
        // Check escape velocity
        if (v * v > vesc2(g, h)) {
            cout << "Escape velocity reached" << endl;
            return 1;
        }
        // Save velocity before we update it
        vold = v;
        // update velocity
        v += dt * (T / M - g);
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

    cout << h << endl;

    return 0;
}

double grav(double h) { return 3.962e5 / (h + r_earth) / (h + r_earth); }

double vesc2(double g, double h) { return (2 * g * (h + r_earth)); }