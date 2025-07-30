#include "Database.hpp"
#include "utils/CsvParser.hpp"
#include "AppException.hpp"

#include <fstream>
#include <sstream>
#include <iostream>

Database::Database(const std::string& usersPath, const std::string& moviesPath) {
    loadMovies(moviesPath);
    loadUsers(usersPath);
}

void Database::loadMovies(const std::string& path) {
    auto lines = CsvParser::parse(path);
    for (const auto& line : lines) {
        auto movie = std::make_shared<Movie>(Movie::createMovie(line));
        movieMap[movie->getName()] = movie;
    }
}

void Database::loadUsers(const std::string& path) {
    auto lines = CsvParser::parse(path);
    for (const auto& line : lines) {
        users.push_back(User::createUser(line, movieMap));
    }
}

const std::unordered_map<std::string, std::shared_ptr<Movie>>& Database::getMovieMap() const {
    return movieMap;
}

const std::vector<User>& Database::getUsers() const {
    return users;
}

const std::shared_ptr<Movie>& Database::getMovieByName(const std::string& name) const {
    auto it = movieMap.find(name);
    if (it == movieMap.end()) {
        throw MovieNotFound(name);
    }
    return it->second;
}

const User& Database::getUserByName(const std::string& username) const {
    for (const auto& user : users) {
        if (user.getUsername() == username)
            return user;
    }
    throw UserNotFound(username);
}

std::vector<std::shared_ptr<Movie>> Database::getAllMovies() const {
    std::vector<std::shared_ptr<Movie>> result;
    for (const auto& pair : movieMap) {
        result.push_back(pair.second);
    }
    return result;
}
