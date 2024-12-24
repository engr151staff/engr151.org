#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    srand(0);
    for (size_t i = 0; i < 10; ++i) {
        cout << rand() << endl;
    }
    return 0;
}