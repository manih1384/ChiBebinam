#include "Database.hpp"
#include "AppException.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

Database::Database(const std::string& usersPath, const std::string& moviesPath) {
    loadMovies(moviesPath);
    loadUsers(usersPath);
}

void Database::loadMovies(const std::string& path) {
    std::vector<std::vector<std::string>> lines = CsvParser::parse(path);
    for (const std::vector<std::string>& line : lines) {
        std::shared_ptr<Movie> movie = std::make_shared<Movie>(Movie::createMovie(line));
        movieMap[movie->getName()] = movie;
    }
}

void Database::loadUsers(const std::string& path) {
    std::vector<std::vector<std::string>> lines = CsvParser::parse(path);
    for (const std::vector<std::string>& line : lines) {
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
    for (const User& user : users) {
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


std::vector<std::shared_ptr<Movie>> Database::getMoviesByCast(const std::string& castMember) const {
    std::vector<std::shared_ptr<Movie>> result;

    for (const auto& pair : movieMap) {
        const std::shared_ptr<Movie>& movie = pair.second;
        if (movie->getCast() == castMember) {
            result.push_back(movie);
        }
    }

    return result;
}