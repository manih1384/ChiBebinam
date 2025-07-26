#include "Database.hpp"
#include "utils/CsvParser.hpp"
#include "AppException.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


Database::Database(const std::string& usersPath, const std::string& moviesPath) {
    loadMovies(moviesPath);
    loadUsers(usersPath);
    
}

void Database::loadUsers(const std::string& path) {
    auto lines = CsvParser::parse(path);
    for (const auto& line : lines) {
        users.push_back(User::createUser(line, movieMap));
    }
}




void Database::loadMovies(const std::string& path) {
    auto lines = CsvParser::parse(path);
    for (const auto& line : lines) {
        auto movie = std::make_shared<Movie>(Movie::createMovie(line));
        movieMap[movie->getName()] = movie;
    }
}


// const std::vector<User>& Database::getUsers() const {
//     return users;
// }

// const std::vector<Movie>& Database::getMovies() const {
//     return movies;
// }
