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
    struct WatchedMovie {
        std::shared_ptr<Movie> movie;
        Rating rating;
    };

    static User createUser(const std::vector<std::string>& row, const std::unordered_map<std::string, std::shared_ptr<Movie>>& movieMap);

    const std::string& getUsername() const;
    const std::vector<WatchedMovie>& getWatchedMovies() const;
    bool hasWatched(const std::shared_ptr<Movie>& movie) const ;
    Rating getRatingFor(const std::shared_ptr<Movie>& movie) const;

private:
    std::string username;
    std::vector<WatchedMovie> watchedMovies;

    User(std::string username, std::vector<WatchedMovie> watchedMovies);
};

#endif // USER_HPP
