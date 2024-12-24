#include "radionuc.hpp"

const double lambdaTc = log(2.0) / 6.0067;

class Tc99 : public radioNuclide
{
public:
    Tc99();
    Tc99(const int popSizeIn);
};

Tc99::Tc99()
: radioNuclide(lambdaTc,0) {}

Tc99::Tc99(const int popSizeIn)
: radioNuclide(lambdaTc,popSizeIn) {}