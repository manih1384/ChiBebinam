#ifndef GENRE_HPP
#define GENRE_HPP

#include <string>
#include <map>

enum class Genre {
    Drama,
    Comedy,
    Action,
    ScienceFiction,
    Horror
};

namespace GenreNames {
    const std::string DRAMA = "Drama";
    const std::string COMEDY = "Comedy";
    const std::string ACTION = "Action";
    const std::string SCI_FI = "Science Fiction";
    const std::string HORROR = "Horror";

    const std::map<std::string, Genre> StringToGenreMap = {
        {DRAMA, Genre::Drama},
        {COMEDY, Genre::Comedy},
        {ACTION, Genre::Action},
        {SCI_FI, Genre::ScienceFiction},
        {HORROR, Genre::Horror}
    };
}

Genre stringToGenre(const std::string& genreStr);

#endif 
