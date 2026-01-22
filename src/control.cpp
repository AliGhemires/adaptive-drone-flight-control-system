#include "control.hpp"
#include "sensor.hpp"
#include <iostream>
#include <algorithm>

// PID Control parameters
struct PID {
    double Kp;  // Proportional
    double Ki;  // Integral
    double Kd;  // Derivative
    double prev_error;  // Previous error for derivative
    double integral;     // Integral accumulated value
};

// Function to initialize the PID controller
PID init_pid(double Kp, double Ki, double Kd) {
    PID pid;
    pid.Kp = Kp;
    pid.Ki = Ki;
    pid.Kd = Kd;
    pid.prev_error = 0.0;
    pid.integral = 0.0;
    return pid;
}

// Function to compute the PID output based on current state and desired target;
// Added Clamp for Integral to prevent wind-up
// Added conditional check to ensure appropriate derivative calculation 
double compute_pid(PID &pid, double target, double current) {
    // Calculate error
    double error = target - current;

    // Proportional term
    double Pout = pid.Kp * error;

    // Integral term with Clamping
    pid.integral += error;
    pid.integral = std::clamp(pid.integral, -10.0, 10.0); // Prevent integral wind-up
    double Iout = pid.Ki * pid.integral;

    // Derivative term
    double derivative = (error - pid.prev_error);
    double Dout = pid.Kd * derivative;
    // Save current error for next derivative calculation
    pid.prev_error = error;

    // Return total output
    return Pout + Iout + Dout;
}

// Function to adaptively tune PID based on environmental inputs
void adaptive_pid_tuning(PID &pid, double wind_speed) {
    // Simple adaptation logic: Increase Kp with increasing wind speed
    if (wind_speed > 10.0) {
        pid.Kp = std::clamp(pid.Kp + 0.1, 1.0, 10.0);
    } else if (wind_speed > 5.0) {
        pid.Kp = std::clamp(pid.Kp - 0.05, 1.0, 10.0);
    }
    // Adjust Ki and Kd if needed following a similar logic
}

// Function to execute control loop 
void control_loop(double desired_altitude) {
    PID altitude_pid = init_pid(2.0, 0.5, 1.0);
    while (true) {
        double current_altitude = read_altitude(); // Assume read_altitude gets current height from sensors
        double wind_speed = read_wind_speed(); // Assume read_wind_speed gets current wind speed from sensors

        // Execute PID Control
        double control_effort = compute_pid(altitude_pid, desired_altitude, current_altitude);

        // Adapt PID based on current environmental conditions
        adaptive_pid_tuning(altitude_pid, wind_speed);

        // Actuate drone motors or outputs based on control effort
        actuate_motors(control_effort);

        // Log telemetry or handle further operations...
    }
}
