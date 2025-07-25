#include "utils/CsvParser.hpp"
#include "AppException.hpp"
#include <fstream>
#include <sstream>

std::vector<std::vector<std::string>> CsvParser::parse(const std::string& filepath, char delimiter) {
    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw FileLoadError(filepath);
    }

    std::vector<std::vector<std::string>> lines;
    std::string full_line;
    
    bool isFirstRow = true;
    while (std::getline(file, full_line)) {
        if (isFirstRow) {
            isFirstRow = false;
            continue;
        }

        std::vector<std::string> line = split(full_line, delimiter);
        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    return lines;
}

std::vector<std::string> CsvParser::split(const std::string& input, char delimiter) {
    std::vector<std::string> tokens;
    std::stringstream ss(input);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}
