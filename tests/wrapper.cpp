#include <iostream>
#include <perfevent/perfevent.hpp>
#include <random>

int main() {
  using namespace std;

  const int n = 10000000;

  // Define some global parameters.
  BenchmarkParameters params;
  params.setParam("n", to_string(n));

  // Initialize stuff before measurement.
  mt19937 rng{};
  decltype(rng()) result{};

  {
    // Change local parameters, such as the name or the number of threads.
    params.setParam("name", "mt19937");
    // Start the measurement by construction and decide on displaying header.
    bool header = true;
    PerfEventBlock e(n, params, header);

    // Do the benchmark.
    for (auto i = n; i > 0; --i) {
      result += rng();
    }

    // End the measurement at the end of the scope.
  }

  cout << "result = " << result << "\n";
}