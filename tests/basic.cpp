#include <iostream>
#include <perfevent/perfevent.hpp>
#include <random>

int main() {
  using namespace std;

  const int n = 10000000;

  // Start the measurement.
  PerfEvent e;
  e.startCounters();

  // The following code will be measured.
  mt19937 rng{};
  decltype(rng()) result{};
  for (auto i = n; i > 0; --i) result += rng();

  // Stop the measurement.
  e.stopCounters();
  // Print measurement scaled by n.
  e.printReport(cout, n);

  cout << "result = " << result << "\n";
}