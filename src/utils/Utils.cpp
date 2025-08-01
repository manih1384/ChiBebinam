#include "utils/Utils.hpp"
#include <fstream>
#include <sstream>
#include <regex>


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

std::vector<std::string> CsvParser::splitOnQuotes(const std::string& input) {
    std::vector<std::string> tokens;
    std::regex pattern(R"'("([^"]*)"|(\S+))'");

    std::smatch match;

    std::string s = input;
    while (std::regex_search(s, match, pattern)) {
        if (match[1].matched) {
            tokens.push_back(match[1].str()); 
        } else {
            tokens.push_back(match[2].str()); 
        }
        s = match.suffix();
    }
    return tokens;
}