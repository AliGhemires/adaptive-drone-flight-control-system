#include "sensor.hpp"
#include <iostream>
#include <vector>
#include <random>

// Placeholder for environmental data
struct EnvironmentalData {
    float wind_speed;
    float temperature;
};

// Sensor class to handle environmental data
class Sensor {
public:
    Sensor();
    ~Sensor();

    // Function to initialize sensors
    void init();

    // Function to fetch current sensor data
    EnvironmentalData read_data();

private:
    EnvironmentalData current_data;
    std::default_random_engine generator;
    std::uniform_real_distribution<float> wind_distribution;
    std::uniform_real_distribution<float> temp_distribution;
};

Sensor::Sensor() : 
    wind_distribution(0.0, 10.0), 
    temp_distribution(0.0, 40.0) 
{
    // Constructor - Initialize random number generator
    std::random_device rd;
    generator.seed(rd());
}

Sensor::~Sensor() {
    // Destructor - Clean up resources if needed
}

void Sensor::init() {
    // Initialize sensor hardware
    std::cout << "Sensor initialized." << std::endl;
}

EnvironmentalData Sensor::read_data() {
    // For simulation purposes, generate mock data
    current_data.wind_speed = wind_distribution(generator); // Simulate wind speed [0.0, 10.0]
    current_data.temperature = temp_distribution(generator); // Simulate temperature [0.0, 40.0]
    std::cout << "Reading sensor data: Wind Speed = " << current_data.wind_speed 
              << " m/s, Temperature = " << current_data.temperature << " C" << std::endl;
    return current_data;
}

// Example main for testing sensor
int main() {
    Sensor sensor;
    sensor.init();
    for (int i = 0; i < 5; ++i) {
        sensor.read_data();
    }
    return 0;
}
