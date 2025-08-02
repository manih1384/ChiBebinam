#include "enums/Genre.hpp"
#include "AppException.hpp"
#include "utils/Utils.hpp"

Genre stringToGenre(const std::string& genreStr) {
    std::string trimmed = CsvParser::trim(genreStr);
    auto it = GenreNames::StringToGenreMap.find(trimmed);
    if (it == GenreNames::StringToGenreMap.end()) {
        throw InvalidGenreString(trimmed);
    }
    return it->second;
}
