#include "entities/User.hpp"
#include "utils/CsvParser.hpp"
#include "AppException.hpp"
#include <iostream>
#include <algorithm>

User::User(std::string username, std::vector<WatchedMovie> watchedMovies)
    : username(std::move(username)), watchedMovies(std::move(watchedMovies)) {}

const std::string& User::getUsername() const {
    return username;
}

const std::vector<User::WatchedMovie>& User::getWatchedMovies() const {
    return watchedMovies;
}

User User::createUser(const std::vector<std::string>& row, const std::unordered_map<std::string, std::shared_ptr<Movie>>& movieMap) {
    if (row.size() != 3) {
        throw MalformedUserRow();
    }

    std::string username = row[0];
    auto movieNames = CsvParser::split(row[1], ';');
    auto ratingStrings = CsvParser::split(row[2], ';');

    if (movieNames.size() != ratingStrings.size()) {
        throw MalformedUserRow();
    }

    std::vector<WatchedMovie> watched;
    for (size_t i = 0; i < movieNames.size(); ++i) {
        const std::string& name = movieNames[i];
        auto it = movieMap.find(name);
        if (it == movieMap.end()) {
            throw MovieNotFound(name);
        }

        Rating rating = stringToRating(ratingStrings[i]);
        watched.push_back({ it->second, rating });
    }

    return User(std::move(username), std::move(watched));
}





bool User::hasWatched(const std::shared_ptr<Movie>& movie) const {
    for (const WatchedMovie& watched : watchedMovies) {
        if (watched.movie == movie) {
            return true;
        }
    }
    return false;
}
