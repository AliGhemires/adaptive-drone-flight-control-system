#include "control.hpp"
#include "sensor.hpp"
#include <gtest/gtest.h>

// Test Suite for Control Module
class ControlTest : public ::testing::Test {
protected:
    Control control;
    Sensor sensor;

    virtual void SetUp() {
        // Initialize control and sensor before each test
        control = Control();
        sensor = Sensor();
    }
};

// Test case for PID tuning under varying simulated winds
TEST_F(ControlTest, PIDAdjustmentsUnderWind) {
    // Simulate environment
    sensor.setWindSpeed(5.0);
    control.updatePID();
    double kP, kI, kD;
    control.getPIDValues(kP, kI, kD);

    // Test if PID values are within expected range
    EXPECT_GT(kP, 0.0);
    EXPECT_GT(kI, 0.0);
    EXPECT_GT(kD, 0.0);
    EXPECT_LE(kP, 10.0); // Assuming an upper bound for validation
    EXPECT_LE(kI, 1.0);
    EXPECT_LE(kD, 1.0);
}

// Test case for obstacle avoidance
TEST_F(ControlTest, PathCorrectnessWithObstacles) {
    // Set obstacle proximity
    sensor.setObstacleProximity(3.0);
    double expected_safe_x = 5.0; // Define expected safe values based on system constraints
    double expected_safe_y = 5.0;
    double pathX = control.calculatePathX();
    double pathY = control.calculatePathY();

    // Verify that path adjustments are made
    EXPECT_LT(pathX, expected_safe_x);
    EXPECT_LT(pathY, expected_safe_y);
    EXPECT_NEAR(pathX, expected_safe_x, 2.0); // Allow some tolerance
    EXPECT_NEAR(pathY, expected_safe_y, 2.0);
}

// Test case for flight stability during rapid input changes
TEST_F(ControlTest, StabilityUnderRapidInputChanges) {
    control.setTargetAltitude(10.0);
    double desired_stable_altitude = 20.0; // Expected result after adjustment
    control.setTargetAltitude(desired_stable_altitude); // Rapid change
    control.updateFlightControl();

    EXPECT_NEAR(control.getCurrentAltitude(), desired_stable_altitude, 1.0);
}

// Consider additional edge cases for robustness
TEST_F(ControlTest, EdgeCaseHighWindResistance) {
    sensor.setWindSpeed(20.0); // Simulate extremely high wind
    control.updatePID();
    double kP, kI, kD;
    control.getPIDValues(kP, kI, kD);

    EXPECT_GT(kP, 0.0);
    EXPECT_GT(kI, 0.0);
    EXPECT_GT(kD, 0.0);
    EXPECT_LE(kP, 15.0); // Higher limits for extreme situations
    EXPECT_LE(kI, 2.0);
    EXPECT_LE(kD, 2.0);
}

// Main function to run the tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
