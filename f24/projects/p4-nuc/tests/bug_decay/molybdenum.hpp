#include "radionuc.hpp"

const double lambdaMo = log(2.0) / 65.94;

class Mo99 : public radioNuclide {
  public:
    Mo99();
    Mo99(const int popSizeIn);
};

Mo99::Mo99() : radioNuclide(lambdaMo, 0) {}

Mo99::Mo99(const int popSizeIn) : radioNuclide(lambdaMo, popSizeIn) {}