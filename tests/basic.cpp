#include <iostream>
#include <perfevent/perfevent.hpp>
#include <random>

int main() {
  using namespace std;

  const int n = 10000000;

  PerfEvent e;
  e.startCounters();

  mt19937 rng{};
  decltype(rng()) result{};
  for (auto i = n; i > 0; --i)  // this code will be measured
    result += rng();

  e.stopCounters();
  e.printReport(cout, n);  // use n as scale factor

  cout << "result = " << result << "\n";
}
