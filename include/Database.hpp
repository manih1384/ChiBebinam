#ifndef DATABASE_HEADER
#define DATABASE_HEADER

#include <string>
#include <vector>
#include <memory>
#include <unordered_map> 
#include "entities/User.hpp"
#include "entities/Movie.hpp"

class Database {
public:
    Database(const std::string& usersPath, const std::string& moviesPath);

    const std::unordered_map<std::string, std::shared_ptr<Movie>>& getMovieMap() const;
    const std::vector<User>& getUsers() const;

private:
    void loadMovies(const std::string& path);
    void loadUsers(const std::string& path);

    std::unordered_map<std::string, std::shared_ptr<Movie>> movieMap;
    std::vector<User> users;
};

#endif // DATABASE_HEADER
