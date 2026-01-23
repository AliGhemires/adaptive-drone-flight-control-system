# Adaptive Drone Flight Control System

## Overview
The **Adaptive Drone Flight Control System** is designed to enhance the stability and performance of drones operating in varied environmental conditions. By implementing adaptive control techniques, this system ensures drones maintain stable operation even in dynamic conditions such as wind and obstacles.

## Motivation
The primary goal of this project is to create a resilient flight control system that adapts in real-time to changing environmental factors, thereby optimizing drone performance and safety.

## Features
- Real-time PID tuning based on the wind profile.
- Dynamic flight path adjustments based on obstacle proximity.
- Logging of flight data for further analysis.
- Visual feedback for real-time control adjustments.

## Key Concepts
- Dynamic PID Control
- Kalman Filtering for state estimation
- Real-time environmental data processing
- User-driven adaptive control adjustments

## Installation
To build and run the Adaptive Drone Flight Control System, follow these steps:

1. **Clone the repository:** 
 ```bash
 git clone https://github.com/yourusername/adaptive-drone-control.git
 cd adaptive-drone-control
 ```

2. **Create a build directory:** 
 ```bash
 mkdir build
 cd build
 ```

3. **Run CMake:** 
 ```bash
 cmake ..
 ```

4. **Build the project:** 
 ```bash
 make
 ```

5. **Run the drone control application:** 
 ```bash
 ./drone_control --start
 ```

## Command Line Interface (CLI) Commands
- Start the drone control: 
 ```bash
 ./drone_control --start
 ```

- Stop the drone control: 
 ```bash
 ./drone_control --stop
 ```

- Set PID parameters: 
 ```bash
 ./drone_control --set-pid 1.0 0.01 0.5
 ```

- Simulate wind conditions: 
 ```bash
 ./drone_control --simulate --wind 5.0
 ```

## Example Output
When executing the command to start the system and simulate wind, the output could look like this:
```
Starting drone control system...
---
Simulating wind conditions: 5.0 m/s
Adjusting PID parameters: Kp = 1.0, Ki = 0.01, Kd = 0.5
Current Altitude: 100m
Current Speed: 20m/s
Wind Impact: -2.5m/s
Adjusted Flight Path: Optimize for obstacle at 50m
---
Drone control system is actively monitoring...
``` 

## Testing
To run the tests for the Adaptive Drone Flight Control System, execute the following command from the `build` directory:
```bash
make test
``` 
This will run all unit tests and integration tests.

## Repo Layout
```
adaptive-drone-control/
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

## Additional Features
- Edge case detection and handling for extreme weather conditions, ensuring consistent performance.

## Notes
- Ensure deterministic responses from CLI commands for reproducibility.
- Test the system in controlled environments before deploying in real-world scenarios to ensure safety.

By utilizing this Adaptive Drone Flight Control System, users can effectively manage the complexities of drone operation in various challenging environments.
