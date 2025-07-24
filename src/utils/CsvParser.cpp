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

    while (std::getline(file, full_line)) {
        std::vector<std::string> line;
        std::stringstream ss(full_line);
        std::string token;

        while (std::getline(ss, token, delimiter)) {
            line.push_back(token);
        }

        if (!line.empty()) {
            lines.push_back(line);
        }
    }

    return lines;
}
