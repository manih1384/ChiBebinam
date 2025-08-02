#ifndef MOVIE_HPP
#define MOVIE_HPP

#include <string>
#include <vector>
#include "enums/Genre.hpp"

class Movie {
public:
    Movie(const std::string& name,
          const std::string& director,
          const std::string& cast,
          Genre genre,
          int imdbScore);

    static Movie createMovie(const std::vector<std::string>& row);

    const std::string& getName() const;
    const std::string& getDirector() const;
    const std::string& getCast() const;
    Genre getGenre() const;
    int getImdbScore() const;

private:
    std::string name;
    std::string director;
    std::string cast;
    Genre genre;
    int imdbScore;
};

#endif
