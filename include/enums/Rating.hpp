#ifndef RATING_HPP
#define RATING_HPP

#include <string>
#include <map>

enum class Rating {
    Perfect,
    Average,
    Poor,
    Unknown
};

namespace RatingNames {
    const std::string PERFECT = "Perfect";
    const std::string AVERAGE = "Average";
    const std::string POOR = "Poor";

    const std::map<std::string, Rating> StringToRatingMap = {
        {PERFECT, Rating::Perfect},
        {AVERAGE, Rating::Average},
        {POOR, Rating::Poor}
    };
}

Rating stringToRating(const std::string& str);

#endif 
