#include "ChiBebinam.hpp"
#include "AppException.hpp"
#include "utils/Constants.hpp"

#include <iostream>

ChiBebinam::ChiBebinam(int argc, char* argv[]) {
    if (argc < REQUIRED_ARG_COUNT) {
        throw InvalidArguments();
    }

    usersFilePath = argv[ARG_USERS_PATH_INDEX];
    moviesFilePath = argv[ARG_MOVIES_PATH_INDEX];
}

void ChiBebinam::run() {
    

    // throw FileLoadError if fail

    handleCommand();
}

void ChiBebinam::handleCommand() {
    std::string input;
    std::cout << PROMPT;
    while (std::getline(std::cin, input)) {
        if (input == "exit" || input == "quit") break;

        // TODO: implement command parsing and dispatch here
        std::cout << "[WARN] Command handling not implemented yet" << std::endl;

        std::cout << PROMPT;
    }
}
