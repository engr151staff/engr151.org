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