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

## Authors
- Original Autor: Viktor Leis
- Fork Author: Markus Pawellek (markuspawellek@gmail.com)

## Requirements
- Operating System: Linux
- Minimal Standard: C++11

## Support
- Compiler: GCC | Clang | Intel
- Build System: CMake | build2

## Getting and Including the Code
### Project Inlining for build2/CMake Projects and Projects without Build Systems
Go into your project folder.
Optionally, go into the specific folder of your project for external source code.
Run the following command to get the code.
```
  curl https://raw.githubusercontent.com/lyrahgames/perfevent/master/perfevent/perfevent.hpp --create-dirs -o perfevent/perfevent.hpp
```
If you are using no build system, make sure to add the current directory to the standard include paths of your compiler by using a flag.
In CMake, you can do this by using `include_directories` or `target_include_directories`.
In build2, use the configuration variable `cxx.poptions` in your `buildfile` and add the specific include flag.

### build2 Package Dependency for build2 Projects
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

### build2 Package Installation for build2 Projects and Projects without Build System
Create a build2 configuration for packages if it does not exist already.
Define a valid installation path which can be found by the compiler.
Use specific options, such as to state the compiler with its flags, if necessary.
```
bpkg -d build2-packages cc \
  config.install.root=/usr/local \
  config.install.sudo=sudo
```
Get the latest package release and build it.
```
bpkg build https://github.com/lyrahgames/perfevent.git
```
Install the built package.
```
bpkg install perfevent
```
For uninstalling, do the following.
```
bpkg uninstall perfevent
```
Because the library consists only of header files, the following can be omitted.
But it is recommended to do it otherwise, such that all dependencies are stated explicitly.
In the appropriate `buildfile`, import the library by the following code and put the variable into the prerequisites of your target.
```
import perfevent_lib = perfevent%lib{perfevent}
```
If you are using a `manifest` file, state `perfevent` as a requirement.
```
requires: perfevent
```

### CMake Package Installation for CMake Projects and Projects without Build System
Download the repository and create a configuration.
```
git clone https://github.com/lyrahgames/perfevent.git
mkdir perfevent-cmake-build
cd perfevent-cmake-build
cmake ../perfevent
```
Optionally, build and run the tests.
```
cmake --build .
ctest --verbose
```
Install the library and the CMake package.
```
sudo cmake --build . --target install
```
To uninstall the library do the following.
```
sudo cmake --build . --target uninstall
```
Because the library consists only of header files, the following can be omitted.
But it is recommended to do it otherwise, such that all dependencies are stated explicitly.
In the appropriate `CMakeLists.txt` file, use `find_package(perfevent)` to find the library and link with the imported target `perfevent::perfevent` by using `target_link_libraries`.
The following code shows an example.
```cmake
find_package(perfevent REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE perfevent::perfevent)
```

### CMake Package Export from Build Configuration for CMake Projects
Download the repository and create a configuration.
```
git clone https://github.com/lyrahgames/perfevent.git
mkdir perfevent-cmake-build
cd perfevent-cmake-build
cmake ../perfevent
```
Through the standard CMake package export you can externally use the library from the build tree.
In the appropriate `CMakeLists.txt` file, use `find_package(perfevent)` to find the library and link with the imported target `perfevent::perfevent` by using `target_link_libraries`.
The following code shows an example.
```cmake
find_package(perfevent REQUIRED)
add_executable(main main.cpp)
target_link_libraries(main PRIVATE perfevent::perfevent)
```

## Usage and Examples
### Basic
The following code snippet demonstrates the basic usage.
```c++
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
    for (auto i = n; i > 0; --i)
      result += rng();

    // Stop the measurement.
    e.stopCounters();
    // Print measurement scaled by n.
    e.printReport(cout, n);

    cout << "result = " << result << "\n";
  }
```
After compiling the program, the result on the terminal should be something like this.
```
cycles, instructions, L1-misses, LLC-misses, branch-misses, task-clock,    scale,  IPC, CPUs,  GHz 
 50.36,        75.56,      0.00,       0.00,          0.51,      26.81, 10000000, 1.50, 1.00, 1.88 
result = 21475859227138269
```

### PerfEventBlock as a Convenience Wrapper
According to the RAII principle, the structure `PerfEventBlock` can be used as a convenient wrapper as shown in the following snippet.
```c++
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
```
The following should be the output of the program.
```
       n,         name, time sec, cycles, instructions, L1-misses, LLC-misses, branch-misses, task-clock,    scale,  IPC, CPUs,  GHz 
10000000, std::mt19937,     0.02,   8.08,        33.23,      0.00,       0.00,          0.00,       1.79, 10000000, 4.11, 1.00, 4.51 
result = 21475859227138269
```

## Troubleshooting
You may need to run `sudo sysctl -w kernel.perf_event_paranoid=-1` and/or add `kernel.perf_event_paranoid = -1` to `/etc/sysctl.conf`