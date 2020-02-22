#include <iostream>
#include <perfevent/perfevent.hpp>
#include <random>

int main() {
  const int n = 10000000;
  std::mt19937 rng{};

  BenchmarkParameters params;
  params.setParam("n", std::to_string(n));
  decltype(rng()) result{};
  {
    params.setParam("name", "std::mt19937");
    PerfEventBlock e(n, params, true);
    for (auto i = n; i > 0; --i) {
      result += rng();
    }
  }
  std::cout << "result = " << result << "\n";
}