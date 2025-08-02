#include "enums/Rating.hpp"
#include "AppException.hpp"
#include "utils/Utils.hpp"

Rating stringToRating(const std::string& str) {
    std::string trimmed = CsvParser::trim(str);
    auto it = RatingNames::StringToRatingMap.find(trimmed);
    if (it == RatingNames::StringToRatingMap.end()) {
        throw InvalidRatingString(trimmed);
    }
    return it->second;
}


