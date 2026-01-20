# Adaptive Drone Flight Control System

## Overview
The **Adaptive Drone Flight Control System** is engineered to augment drone stability and performance across diverse environmental conditions. By implementing sophisticated adaptive control strategies, the system empowers drones to dynamically adjust their flight paths, ensuring safe and dependable operation amidst varying scenarios such as wind changes and proximity to obstacles. Leveraging C++ and CMake, the project is rooted in modular design principles and extensive system testing.

## Features
- Real-time PID tuning based on prevailing wind conditions.
- Dynamic flight path adjustments responding to nearby obstacles.
- Flight data logging for comprehensive post-operation analysis.
- Visual feedback mechanism to indicate control adjustments during real-time operations.

## Installation
To install the project, proceed with the following steps:

1. **Clone the repository:**
 ```bash
 git clone https://github.com/your-username/adaptive-drone-flight-control.git
 cd adaptive-drone-flight-control
 ```

2. **Set up the build environment:**
 ```bash
 mkdir build && cd build
 ```

3. **Generate the build configuration with CMake:**
 ```bash
 cmake ..
 ```

4. **Compile the project:**
 ```bash
 make
 ```

## Running the Program
With the project built, you can initiate the drone control system using the command:
```bash
./drone_control --start
```
To halt the system or modify parameters, use these commands:
```bash
./drone_control --stop
./drone_control --set-pid 1.0 0.01 0.5
./drone_control --simulate --wind 5.0
```

## Example Output
After executing the control system, an output example might be:
```plaintext
Starting Drone Control System...
Current Wind Speed: 5.0 m/s
Adjusting PID settings...
New PID values: Kp = 1.0, Ki = 0.01, Kd = 0.5
Adjusting flight path based on obstacles...
Flight path adjusted successfully!
Drone Status: Operational
``` 

## Running Tests
The project incorporates a testing framework to ensure system robustness. To execute the tests, navigate to the build directory and run:
```bash
make test
```
This command executes the predefined unit and integration tests under various challenging conditions, including PID adjustments and simulated obstacle encounters.

## Project Structure
```plaintext
adaptive-drone-flight-control/
├── CMakeLists.txt
├── README.md
├── include/
│ ├── cli.hpp
│ ├── control.hpp
│ └── sensor.hpp
├── src/
│ ├── cli.cpp
│ ├── control.cpp
│ ├── main.cpp
│ ├── sensor.cpp
│ └── utils.cpp
└── tests/
 ├── test_control.cpp
 └── test_sensor.cpp
```

## Contributing
Contributions are enthusiastically welcomed! Raise a pull request or open an issue for any suggestions or enhancements.

## Notes
Ensure that CLI commands consistently provide deterministic responses to facilitate reproducible operation and testing.
