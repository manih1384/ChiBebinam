#ifndef DATABASE_HEADER
#define DATABASE_HEADER


#include <string>
#include <vector>
#include "entities/User.hpp"
#include "entities/Movie.hpp"

class Database {
public:
    Database(const std::string& usersPath, const std::string& moviesPath);

    // const std::vector<User>& getUsers() const;
    // const std::vector<Movie>& getMovies() const;

private:
    // std::vector<User> users;
    // std::vector<Movie> movies;

    void loadUsers(const std::string& path);
    void loadMovies(const std::string& path);
};


#endif
