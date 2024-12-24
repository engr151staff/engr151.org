#include "molybdenum.hpp"
#include "technetium.hpp"

using namespace std;

bool testTcDefaultCtor();
bool testTcCustomCtor();
bool testMoDefaultCtor();
bool testMoCustomCtor();

int main() {
    bool failed = false;

    if (!testTcDefaultCtor()) {
        cout << "Check implementation of default constructor for Tc-99."
             << endl;
        failed = true;
    }

    if (!testTcCustomCtor()) {
        cout << "Check implementation of custom constructor for Tc-99." << endl;
        failed = true;
    }

    if (!testMoDefaultCtor()) {
        cout << "Check implementation of default constructor for Mo-99."
             << endl;
        failed = true;
    }

    if (!testMoCustomCtor()) {
        cout << "Check implementation of custom constructor for Mo-99." << endl;
        failed = true;
    }

    if (!failed) {
        cout << "All checks pass." << endl;
    }
    return 0;
}

bool testTcDefaultCtor() {
    Tc99 tc;
    return (tc.Count() == 0);
}

bool testTcCustomCtor() {
    Tc99 tc(1013);
    return (tc.Count() == 1013);
}

bool testMoDefaultCtor() {
    Mo99 mo;
    return (mo.Count() == 0);
}

bool testMoCustomCtor() {
    Mo99 mo(54321);
    return (mo.Count() == 54321);
}