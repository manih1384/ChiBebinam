#include "ChiBebinam.hpp"
#include <iostream>
#include <string>

ChiBebinam::ChiBebinam(Database& database) : db(database) {}

void ChiBebinam::run() {
    // You can log or prompt CLI here if needed
    handleCommand();
}

void ChiBebinam::handleCommand() {
    std::string input;
    std::cout << "> ";

    while (std::getline(std::cin, input)) {
        if (input == "exit" || input == "quit") break;

        // TODO: actual command processing
        std::cout << "[WARN] Command not implemented yet\n";
        std::cout << "> ";
    }
}
