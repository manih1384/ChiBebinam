#ifndef GENRE_RECOMMENDER_HEADER
#define GENRE_RECOMMENDER_HEADER

#include "Recommender.hpp"

class GenreRecommender : public Recommender {
public:
    std::vector<std::shared_ptr<Movie>> recommend(
        const User& user,
        const std::vector<std::shared_ptr<Movie>>& movies,
        const std::string& genre) override;

    std::vector<std::shared_ptr<Movie>> recommend(
        const std::vector<std::shared_ptr<Movie>>& movies,
        const std::string& genre) override;

private:
    float calculateScore(const User& user, const std::shared_ptr<Movie>& movie);
    float calculateDirectorEffect(const User& user, const std::shared_ptr<Movie>& movie);
    float calculateCastEffect(const User& user, const std::shared_ptr<Movie>& movie);
};

#endif
