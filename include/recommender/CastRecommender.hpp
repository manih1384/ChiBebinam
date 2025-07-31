#ifndef CAST_RECOMMENDER_HEADER
#define CAST_RECOMMENDER_HEADER

#include "Recommender.hpp"
#include <vector>
#include <memory>
#include <string>
#include "utils/Utils.hpp"
class CastRecommender : public Recommender {
public:
    std::vector<std::shared_ptr<Movie>> recommend(
        const User& user,
        const std::vector<std::shared_ptr<Movie>>& movies,
        const std::string& cast) override;

    std::vector<std::shared_ptr<Movie>> recommend(
        const std::vector<User>& users,
        const std::vector<std::shared_ptr<Movie>>& movies,
        const std::string& cast) override;

private:

    std::vector<std::shared_ptr<Movie>> filterMoviesByCast(
        const std::vector<std::shared_ptr<Movie>>& movies,
        const std::string& cast) const;
};

#endif