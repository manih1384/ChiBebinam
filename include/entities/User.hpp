#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <vector>
#include <memory>
#include "entities/Movie.hpp"
#include "utils/enums.hpp"
#include <unordered_map>
class User {
public:
    struct WatchedEntry {
        std::shared_ptr<Movie> movie;
        Rating rating;
    };

    static User createUser(const std::vector<std::string>& row, const std::unordered_map<std::string, std::shared_ptr<Movie>>& movieMap);

    const std::string& getUsername() const;
    const std::vector<WatchedEntry>& getWatchedMovies() const;

private:
    std::string username;
    std::vector<WatchedEntry> watchedMovies;
    
    User(std::string username, std::vector<WatchedEntry> watchedMovies);
};

#endif // USER_HPP
