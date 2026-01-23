#include <gtest/gtest.h>
#include "sensor.hpp"

// Mock class to simulate the sensor behavior
class MockSensor : public Sensor {
public:
    MockSensor() : Sensor() {}
    double getWindSpeed() override {
        return windSpeed;
    }
    void setWindSpeed(double speed) {
        windSpeed = speed;
    }

private:
    double windSpeed = 0.0;
};

// Test suite for the Sensor class
TEST(SensorTest, TestWindSpeedRetrieval) {
    MockSensor sensor;
    sensor.setWindSpeed(5.0);
    EXPECT_DOUBLE_EQ(sensor.getWindSpeed(), 5.0);
}

TEST(SensorTest, TestWindSpeedChange) {
    MockSensor sensor;
    sensor.setWindSpeed(10.0);
    EXPECT_DOUBLE_EQ(sensor.getWindSpeed(), 10.0);
    sensor.setWindSpeed(0.0);
    EXPECT_DOUBLE_EQ(sensor.getWindSpeed(), 0.0);
}

TEST(SensorTest, TestWindSpeedNegativeValue) {
    MockSensor sensor;
    sensor.setWindSpeed(-3.0);
    EXPECT_DOUBLE_EQ(sensor.getWindSpeed(), -3.0);
}

// Additional Tests for Edge Cases
TEST(SensorTest, TestWindSpeedExtremeLow) {
    MockSensor sensor;
    sensor.setWindSpeed(-1000.0);
    EXPECT_DOUBLE_EQ(sensor.getWindSpeed(), -1000.0);
}

TEST(SensorTest, TestWindSpeedExtremeHigh) {
    MockSensor sensor;
    sensor.setWindSpeed(1000.0);
    EXPECT_DOUBLE_EQ(sensor.getWindSpeed(), 1000.0);
}

TEST(SensorTest, TestWindSpeedMinimumPositive) {
    MockSensor sensor;
    sensor.setWindSpeed(1e-9);
    EXPECT_DOUBLE_EQ(sensor.getWindSpeed(), 1e-9);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
