#ifndef CSV_PARSER_HPP
#define CSV_PARSER_HPP

#include <string>
#include <vector>

class CsvParser {
public:
    static std::vector<std::vector<std::string>> parse(const std::string& filepath, char delimiter = ',');
    static std::vector<std::string> split(const std::string& input, char delimiter);
    static std::vector<std::string> splitOnQuotes(const std::string& input);
};

#endif
