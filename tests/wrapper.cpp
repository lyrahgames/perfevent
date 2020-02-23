#include <iostream>
#include <perfevent/perfevent.hpp>
#include <random>

int main() {
  using namespace std;

  const int n = 10000000;

  BenchmarkParameters params;
  params.setParam("n", to_string(n));

  mt19937 rng{};
  decltype(rng()) result{};
  {
    params.setParam("name", "mt19937");
    PerfEventBlock e(n, params, true);

    for (auto i = n; i > 0; --i) {
      result += rng();
    }
  }

  cout << "result = " << result << "\n";
}