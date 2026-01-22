#include "cli.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdexcept>

// Command Line Interface for the Adaptive Drone Flight Control System
namespace DroneControl {

class CLI {
public:
    // Starts the drone control system
    void start() {
        std::cout << "Drone Control System Started\n";
    }

    // Stops the drone control system
    void stop() {
        std::cout << "Drone Control System Stopped\n";
    }

    // Sets the PID controller parameters
    void setPID(double p, double i, double d) {
        std::cout << "PID Values Set - P: " << p << ", I: " << i << ", D: " << d << "\n";
    }

    // Simulates environmental conditions like wind
    void simulate(double windSpeed) {
        std::cout << "Simulating environmental conditions with wind speed: " << windSpeed << " m/s\n";
    }

    // Parses and executes user commands
    void parseCommand(const std::string& command) {
        std::istringstream iss(command);
        std::string cmd;
        std::vector<std::string> args;

        if (!(iss >> cmd)) {
            throw std::runtime_error("Invalid command");
        }

        std::string arg;
        while (iss >> arg) {
            args.push_back(arg);
        }

        try {
            if (cmd == "--start") {
                start();
            } else if (cmd == "--stop") {
                stop();
            } else if (cmd == "--set-pid") {
                if (args.size() == 3) {
                    double p = std::stod(args[0]);
                    double i = std::stod(args[1]);
                    double d = std::stod(args[2]);
                    setPID(p, i, d);
                } else {
                    throw std::invalid_argument("Invalid number of PID parameters");
                }
            } else if (cmd == "--simulate") {
                if (args.size() == 2 && args[0] == "--wind") {
                    double windSpeed = std::stod(args[1]);
                    simulate(windSpeed);
                } else {
                    throw std::invalid_argument("Invalid simulate command");
                }
            } else {
                throw std::invalid_argument("Unknown command: " + cmd);
            }
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        } catch (const std::out_of_range& e) {
            std::cerr << "Error: Input value out of range" << std::endl;
        }
    }
};

} // namespace DroneControl

// Main function for demonstration purposes
int main(int argc, char* argv[]) {
    DroneControl::CLI cli;

    try {
        std::string command;
        while (true) {
            std::cout << "> ";
            std::getline(std::cin, command);
            cli.parseCommand(command);
        }
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
