#include "entities/User.hpp"
#include "utils/CsvParser.hpp"
#include "AppException.hpp"
#include <algorithm>
#include <iostream>
User::User(std::string username, std::vector<WatchedEntry> watchedMovies)
    : username(std::move(username)), watchedMovies(std::move(watchedMovies)) {}


const std::string& User::getUsername() const {
    return username;
}

const std::vector<User::WatchedEntry>& User::getWatchedMovies() const {
    return watchedMovies;
}

static std::shared_ptr<Movie> findMovieByName(const std::string& name, const std::vector<std::shared_ptr<Movie>>& pool) {
    for (const auto& movie : pool) {
        if (movie->getName() == name)
            return movie;
    }
    throw MovieNotFound(name);
}

static std::vector<User::WatchedEntry> buildWatchedList(const std::vector<std::string>& movieNames,
                                                        const std::vector<std::string>& ratingStrings,
                                                        const std::vector<std::shared_ptr<Movie>>& pool) {

    std::vector<User::WatchedEntry> watched;
    for (int i = 0; i < movieNames.size(); ++i) {
        auto movie = findMovieByName(movieNames[i], pool);
        Rating rating = stringToRating(ratingStrings[i]);
        watched.push_back({ movie, rating });
    }

    return watched;
}

User User::createUser(const std::vector<std::string>& row, const std::vector<std::shared_ptr<Movie>>& moviePool) {
    if (row.size() != 3) {
        throw MalformedUserRow();
    }

    std::string username = row[0];
    auto movieNames = CsvParser::split(row[1], ';');
    auto ratingStrings = CsvParser::split(row[2], ';');



    auto watched = buildWatchedList(movieNames, ratingStrings, moviePool);
    return User(username, watched);
}
