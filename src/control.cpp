#include "control.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <thread>

// PID controller class definition
class PIDController {
private:
    double Kp; // Proportional gain
    double Ki; // Integral gain
    double Kd; // Derivative gain
    double previous_error; // for calculating derivative
    double integral; // for calculating integral

public:
    PIDController(double p, double i, double d)
        : Kp(p), Ki(i), Kd(d), previous_error(0.0), integral(0.0) { }

    double update(double setpoint, double measured_value, double dt) {
        // Calculate the error
        double error = setpoint - measured_value;

        // Proportional term
        double P = Kp * error;

        // Integral term
        integral += error * dt;
        double I = Ki * integral;

        // To prevent integral windup, we could clamp integral term if needed.
        // Example clamp: integral = std::clamp(integral, -max_integral, max_integral);

        // Derivative term (prevent division by zero)
        double derivative = (dt > 0) ? (error - previous_error) / dt : 0.0;
        double D = Kd * derivative;

        // Update previous error
        previous_error = error;

        // Return the control variable
        return P + I + D;
    }
};

// Function to adjust the PID parameters dynamically
void adjustPIDParameters(PIDController& pid, double wind_speed) {
    // Validate non-negative wind speed
    if (wind_speed < 0) {
        wind_speed = 0;
    }

    // Example logic to change PID parameters based on wind speed
    double new_Kp = 1.0 + (wind_speed / 10.0);
    double new_Ki = 0.01 * (1 + wind_speed);
    double new_Kd = 0.5 * (1 + (wind_speed / 5.0));
    // Set new parameters to PID controller
    pid = PIDController(new_Kp, new_Ki, new_Kd);
}

// Inverse Kinematics for drone movement
void moveDrone(double target_x, double target_y, double& current_x, double& current_y) {
    // Dummy function to represent inverse kinematics calculation to move the drone
    double dx = target_x - current_x;
    double dy = target_y - current_y;
    double distance = std::sqrt(dx * dx + dy * dy);

    // For simplicity, we move a fixed step towards the target
    if (distance > 0.1) { // Threshold to stop moving
        current_x += dx / distance * 0.1; // Moving step size
        current_y += dy / distance * 0.1;
    }
}

// Main control loop
void controlLoop() {
    PIDController pid(1.0, 0.01, 0.5);
    double target_altitude = 100.0; // Target altitude
    double current_altitude = 0.0;
    double time_step = 0.1; // 100ms time step
    double wind_speed = 5.0; // Example wind speed

    while (true) {
        // Update PID parameters based on environmental feedback
        adjustPIDParameters(pid, wind_speed);

        // Get the control signal based on PID output
        double control_signal = pid.update(target_altitude, current_altitude, time_step);

        // Apply control signal to adjust altitude
        current_altitude += control_signal * time_step;

        // For debug: Move the drone (example)
        double temp_x = 0.0, temp_y = 0.0;
        moveDrone(10.0, 10.0, temp_x, temp_y);

        // Output current status
        std::cout << "Current Altitude: " << current_altitude << std::endl;

        // Sleep for a specified time (simulates real-time control loop interval)
        std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(time_step * 1000)));
    }
}

// Entry point for control functions
int main() {
    controlLoop();
    return 0;
}
