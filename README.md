# PerfEvent: A header-only C++ wrapper for Linux' perf event API
Forked from Viktor Leis to add CMake and build2 packaging support.

![](https://img.shields.io/github/languages/top/lyrahgames/perfevent.svg?style=for-the-badge)
![](https://img.shields.io/github/languages/code-size/lyrahgames/perfevent.svg?style=for-the-badge)
![](https://img.shields.io/github/repo-size/lyrahgames/perfevent.svg?style=for-the-badge)
![](https://img.shields.io/github/license/lyrahgames/perfevent.svg?style=for-the-badge&color=blue)
<!-- [![Website lyrahgames.github.io/pxart](https://img.shields.io/website/https/lyrahgames.github.io/pxart.svg?down_message=offline&label=Documentation&style=for-the-badge&up_color=blue&up_message=online)](https://lyrahgames.github.io/pxart) -->

<b>
<table align="center">
    <tr>
        <td>
            master
        </td>
        <td>
            <a href="https://github.com/lyrahgames/perfevent">
                <img src="https://img.shields.io/github/last-commit/lyrahgames/perfevent/master.svg?logo=github&logoColor=white">
            </a>
        </td>    
        <td>
            <a href="https://circleci.com/gh/lyrahgames/perfevent/tree/master"><img src="https://circleci.com/gh/lyrahgames/perfevent/tree/master.svg?style=svg"></a>
        </td>
        <td>
            <a href="https://codecov.io/gh/lyrahgames/perfevent">
              <img src="https://codecov.io/gh/lyrahgames/perfevent/branch/master/graph/badge.svg" />
            </a>
        </td>
    </tr>
    <!-- <tr>
        <td>
            develop
        </td>
        <td>
            <a href="https://github.com/lyrahgames/perfevent/tree/develop">
                <img src="https://img.shields.io/github/last-commit/lyrahgames/perfevent/develop.svg?logo=github&logoColor=white">
            </a>
        </td>    
        <td>
            <a href="https://circleci.com/gh/lyrahgames/perfevent/tree/develop"><img src="https://circleci.com/gh/lyrahgames/perfevent/tree/develop.svg?style=svg"></a>
        </td>
        <td>
            <a href="https://codecov.io/gh/lyrahgames/perfevent">
              <img src="https://codecov.io/gh/lyrahgames/perfevent/branch/develop/graph/badge.svg" />
            </a>
        </td>
    </tr> -->
    <tr>
        <td>
        </td>
    </tr>
    <tr>
        <td>
            Current
        </td>
        <td>
            <a href="https://github.com/lyrahgames/perfevent">
                <img src="https://img.shields.io/github/commit-activity/y/lyrahgames/perfevent.svg?logo=github&logoColor=white">
            </a>
        </td>
        <!-- <td>
            <img src="https://img.shields.io/github/release/lyrahgames/perfevent.svg?logo=github&logoColor=white">
        </td>
        <td>
            <img src="https://img.shields.io/github/release-pre/lyrahgames/perfevent.svg?label=pre-release&logo=github&logoColor=white">
        </td> -->
        <td>
            <img src="https://img.shields.io/github/tag/lyrahgames/perfevent.svg?logo=github&logoColor=white">
        </td>
        <td>
            <img src="https://img.shields.io/github/tag-date/lyrahgames/perfevent.svg?label=latest%20tag&logo=github&logoColor=white">
        </td>
    </tr>
</table>
</b>

## Requirements
- Operating System: Linux
- Minimal Standard: C++11

## Support
- Compiler: GCC | Clang | Intel
- Build System: CMake | build2

## Getting the Code

### By Inlining it in the project
```
  curl https://raw.githubusercontent.com/lyrahgames/perfevent/master/perfevent/perfevent.hpp --create-dirs -o perfevent/perfevent.hpp
```

```cmake
  target_include_directories()
```



### By Using Git and a Build System
```
  mkdir perfevent
  git clone https://github.com/lyrahgames/perfevent.git
```

### build2 Package for build2 project
Add the following entry to the file `repositories.manifest`.
```
:
role: prerequisite
location: https://github.com/lyrahgames/perfevent.git
```
Add the following dependency entry to the file `manifest`.
Optionally, you can specify the version range.
```
depends: perfevent
```
Import the library in the according `buildfile` and link it to your target by putting it in the prerequisites.
```
import perfevent_lib = perfevent%lib{perfevent}
```

### build2 Package Installation
### CMake Package Installation

### Basic Usage:
```c++
  #include "PerfEvent.hpp"
  ...
  PerfEvent e;
  e.startCounters();
  for (int i=0; i<n; i++) // this code will be measured
    ...
  e.stopCounters();
  e.printReport(std::cout, n); // use n as scale factor
  std::cout << std::endl;
```

This prints something like this:
```
cycles, instructions, L1-misses, LLC-misses, branch-misses, task-clock,    scale, IPC, CPUs,  GHz
 10.97,     28.01,      0.22,       0.00,          0.00,       3.89, 10000000, 2.55, 1.00, 2.82
```

### Usage of PerfEventBlock (convenience wrapper):

```c++
  #include "PerfEvent.hpp"

  // Define some global params
  BenchmarkParameters params;
  params.setParam("name","Dummy Benchmark");
  params.setParam("dataSize","100 GB");

  for (int threads=1;threads<maxThreads;++threads) {

    // Change local parameters like num threads
    params.setParam("threads",numThreads);

    // Only print the header for the first iteration
    bool printHeader=numThreads==1;

    PerfEventBlock e(n,params,printHeader);
    // Counter are started in constructor

    yourBenchmark();

    // Benchmark counters are automatically stopped and printed on destruction of e
  }
```

This prints something like this:
```
           name, dataSize, threads, time sec,      cycles, instructions, L1-misses, LLC-misses, branch-misses, task-clock,   scale,      IPC,     CPUs,      GHz
Dummy Benchmark,   100 GB,       1, 1.400645, 1075.520519,  1931.465504,  8.888315,   0.070063,      0.121389, 280.115649, 5000000, 1.795843, 0.999952, 3.839559
Dummy Benchmark,   100 GB,       2, 1.133364, 2386.772941,  2062.313141, 32.095011,   0.043248,      0.918986, 650.737357, 5000000, 0.864059, 1.870823, 3.667798
...
```

## Basic Example
```c++
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
```

The following should be the output of the program.

```
       n,         name, time sec, cycles, instructions, L1-misses, LLC-misses, branch-misses, task-clock,    scale,  IPC, CPUs,  GHz 
10000000, std::mt19937,     0.02,   8.08,        33.23,      0.00,       0.00,          0.00,       1.79, 10000000, 4.11, 1.00, 4.51 
result = 21475859227138269
```

## Troubleshooting

You may need to run `sudo sysctl -w kernel.perf_event_paranoid=-1` and/or add `kernel.perf_event_paranoid = -1` to `/etc/sysctl.conf`

## Authors
- Original Autor: Viktor Leis
- Fork Author: Markus Pawellek (markuspawellek@gmail.com)