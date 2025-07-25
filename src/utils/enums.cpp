#include "utils/enums.hpp"
#include <regex>





Genre stringToGenre(const std::string& genreStr) {
    if (genreStr == "Drama") return Genre::Drama;
    if (genreStr == "Comedy") return Genre::Comedy;
    if (genreStr == "Action") return Genre::Action;
    if (genreStr == "Science Fiction") return Genre::ScienceFiction;
    if (genreStr == "Horror") return Genre::Horror;

    throw InvalidGenreString(genreStr);
}


std::string trim(const std::string& str) {
    static const std::regex wsRegex("^\\s+|\\s+$");
    return std::regex_replace(str, wsRegex, "");
}

Rating stringToRating(const std::string& ratingStr) {
    std::string trimmed = trim(ratingStr);

    if (trimmed == "Perfect") return Rating::Perfect;
    if (trimmed == "Average") return Rating::Average;
    if (trimmed == "Poor") return Rating::Poor;

    throw InvalidRatingString(trimmed);
}

