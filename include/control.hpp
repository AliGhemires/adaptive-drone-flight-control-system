#ifndef CONTROL_HPP
#define CONTROL_HPP

#include <vector>
#include <iostream>
#include <cmath>

class PIDController {
public:
    // Constructor
    PIDController(double kp, double ki, double kd);

    // Method to update the PID controller
    double update(double setpoint, double current_value, double dt);

    // Setters for PID parameters
    void setKp(double kp);
    void setKi(double ki);
    void setKd(double kd);

    // Getters for PID parameters
    double getKp() const;
    double getKi() const;
    double getKd() const;

private:
    double Kp;  // Proportional gain
    double Ki;  // Integral gain
    double Kd;  // Derivative gain

    double prev_error;  // Previous error for derivative calculation
    double integral;     // Integral error over time

    // Method to clamp the integral value to prevent wind-up
    double clampIntegral(double value, double min, double max) const;
};

class AdaptiveFlightControl {
public:
    // Constructor
    AdaptiveFlightControl();

    // Main control loop method
    void controlLoop(double dt);

    // Method to adjust control parameters based on environmental feedback
    void adjustParameters(double wind_speed, double obstacle_distance);

    // Method to get the environmental data vector
    const std::vector<double>& getEnvironmentalData() const;

private:
    PIDController pidController;
    std::vector<double> environmentalData;

    // Private method to process environmental data
    void processEnvironmentalData();
};

#endif // CONTROL_HPP
