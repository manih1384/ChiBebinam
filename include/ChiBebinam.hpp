#pragma once

#include <string>

class ChiBebinam {
public:
    ChiBebinam(int argc, char* argv[]);
    void run();

private:
    std::string usersFilePath;
    std::string moviesFilePath;

    void handleCommand();
};
