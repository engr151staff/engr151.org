#include <fstream>
#include <iostream>

using namespace std;

double del_t = 0.001;

int main() {
    cout.precision(3);
    double T, ve, M, M_p;
    ifstream input("init.txt");
    input >> T >> ve >> M >> M_p;
    input.close();

    double v = 0;
    while (M > M_p) {
        v = v + T / M * del_t;
        M = M - T * del_t / ve;
    }

    cout << v << endl;

    return 0;
}