#ifndef CHIBEBINAM_HEADER
#define CHIBEBINAM_HEADER
#include "Database.hpp"
#include "recommender/GenreRecommender.hpp"
#include "recommender/CastRecommender.hpp"
#include <string>
#include <vector>

class ChiBebinam {
public:
    ChiBebinam(Database& database);
    void run();

private:
    Database& db;
    GenreRecommender genreRecomm;
    CastRecommender castRecomm;

    void processCommand(const std::string& input);
    void handleGenreRecommendation(const std::vector<std::string>& tokens);
    void handleCastRecommendation(const std::vector<std::string>& tokens);
    void handleOutput(const std::vector<std::shared_ptr<Movie>>& movies, int count);

};


#endif
