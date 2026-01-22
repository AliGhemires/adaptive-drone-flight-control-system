#ifndef CLI_HPP
#define CLI_HPP

#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>

class CLI {
public:
    CLI();
    void start();
    void stop();
    void setPID(double p, double i, double d);
    void simulateWind(double windSpeed);
    void displayHelp();
    void run();
    void parseCommand(const std::string& command);
    void executeCommand(const std::vector<std::string>& commandTokens);

private:
    bool running;
};

#endif // CLI_HPP
