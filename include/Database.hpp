#ifndef DATABASE_HEADER
#define DATABASE_HEADER

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "entities/User.hpp"
#include "entities/Movie.hpp"
#include "utils/Utils.hpp"
class Database {
public:
    Database(const std::string& usersPath, const std::string& moviesPath);

    const std::unordered_map<std::string, std::shared_ptr<Movie>>& getMovieMap() const;
    const std::vector<User>& getUsers() const;

    const std::shared_ptr<Movie>& getMovieByName(const std::string& name) const;
    const User& getUserByName(const std::string& username) const;
    std::vector<std::shared_ptr<Movie>> getAllMovies() const;
    std::vector<std::shared_ptr<Movie>> getMoviesByCast(const std::string& castMember) const;

private:
    void loadMovies(const std::string& path);
    void loadUsers(const std::string& path);

    std::unordered_map<std::string, std::shared_ptr<Movie>> movieMap;
    std::vector<User> users;
};

#endif // DATABASE_HEADER
