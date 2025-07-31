#ifndef ENUMS_HPP
#define ENUMS_HPP

#include <string>
#include "AppException.hpp"

enum class Genre {
    Drama,
    Comedy,
    Action,
    ScienceFiction,
    Horror
};

enum class Rating {
    Perfect,
    Average,
    Poor,
    Unknown
};

Genre stringToGenre(const std::string& genreStr);
Rating stringToRating(const std::string& ratingStr);

#endif 
