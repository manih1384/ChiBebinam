#pragma once

#include <string>
#include <stdexcept>
#include "AppException.hpp"
namespace GenreStrings {
    const std::string Drama = "Drama";
    const std::string Comedy = "Comedy";
    const std::string Action = "Action";
    const std::string ScienceFiction = "Science Fiction";
    const std::string Horror = "Horror";
}

enum class Genre {
    Drama,
    Comedy,
    Action,
    ScienceFiction,
    Horror
};

Genre genreFromString(const std::string& genreStr) {
    using namespace GenreStrings;
    if (genreStr == Drama) return Genre::Drama;
    if (genreStr == Comedy) return Genre::Comedy;
    if (genreStr == Action) return Genre::Action;
    if (genreStr == ScienceFiction) return Genre::ScienceFiction;
    if (genreStr == Horror) return Genre::Horror;

    throw UnknownGenre(genreStr);
}
