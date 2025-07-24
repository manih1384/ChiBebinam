#include "entities/Movie.hpp"
#include "AppException.hpp"
#include <stdexcept>
#include <sstream>

Movie::Movie(const std::string& name,
             const std::string& director,
             const std::string& cast,
             Genre genre,
             int imdbScore)
    : name(name),
      director(director),
      cast(cast),
      genre(genre),
      imdbScore(imdbScore) {}


Movie Movie::createMovie(const std::vector<std::string>& row) {
    if (row.size() != 5) {
        throw CsvRowSizeMismatch();
    }

    std::string name = row[0];
    std::string director = row[1];
    std::string cast = row[2];

    Genre genre;
    try {
        genre = genreFromString(row[3]);
    } catch (const InvalidGenreString& e) {
        throw; 
    }

    int score;
    try {
        score = std::stoi(row[4]);
    } catch (...) {
        throw InvalidImdbScore();
    }

    if (score < 0 || score > 10) {
        throw InvalidImdbScore();
    }

    return Movie(name, director, cast, genre, score);
}

// Getters
const std::string& Movie::getName() const {
    return name;
}

const std::string& Movie::getDirector() const {
    return director;
}

const std::string& Movie::getCast() const {
    return cast;
}

Genre Movie::getGenre() const {
    return genre;
}

int Movie::getImdbScore() const {
    return imdbScore;
}