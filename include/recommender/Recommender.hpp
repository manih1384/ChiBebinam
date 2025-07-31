#ifndef RECOMMENDER_HEADER
#define RECOMMENDER_HEADER

#include <vector>
#include <memory>
#include <string>
#include "../entities/Movie.hpp"
#include "../entities/User.hpp"

class Recommender {
public:
    virtual ~Recommender() = default;

    virtual std::vector<std::shared_ptr<Movie>> recommend(
        const User& user,
        const std::vector<std::shared_ptr<Movie>>& movies,
        const std::string& filter) = 0;

    virtual std::vector<std::shared_ptr<Movie>> recommend(
        const std::vector<User>& Users,
        const std::vector<std::shared_ptr<Movie>>& movies,
        const std::string& filter) = 0;
};

#endif
