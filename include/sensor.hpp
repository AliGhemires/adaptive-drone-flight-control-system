#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <vector>
#include <iostream>

class Sensor {
public:
    // Constructor
    Sensor();
    
    // Initializes sensor parameters
    void initSensors();
    
    // Reads data from the sensor
    std::vector<double> readSensorData();
    
    // Gets wind speed
    double getWindSpeed();
    
    // Gets altitude
    double getAltitude();

    // Updates sensor state based on external environment
    void updateSensorData();
    
    // Allows setting mock values for testing purposes
    void setMockData(double mockWindSpeed, double mockAltitude);

private:
    // Internal storage for wind speed
    double windSpeed;
    
    // Internal storage for altitude
    double altitude;
};

#endif // SENSOR_HPP
