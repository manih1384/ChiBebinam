#include "recommender/CastRecommender.hpp"
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


const auto compareMovies = [](const shared_ptr<Movie>& a, const shared_ptr<Movie>& b) {
    if (a->getImdbScore() != b->getImdbScore()) {
        return a->getImdbScore() > b->getImdbScore();
    }
    return a->getName() < b->getName();
};

vector<shared_ptr<Movie>> CastRecommender::recommend(
    const User& user,
    const vector<shared_ptr<Movie>>& movies,
    const string& cast) {

    Genre favoriteGenre = user.getFavoriteGenre();

    vector<shared_ptr<Movie>> results;

    for (const auto& movie : movies) {
        if (movie->getCast() == cast &&  movie->getGenre() == favoriteGenre && !user.hasWatched(movie)) {
            results.push_back(movie);
        }
    }

    sort(results.begin(), results.end(), compareMovies);

    return results;
}

vector<shared_ptr<Movie>> CastRecommender::recommend(
    const vector<User>& ,
    const vector<shared_ptr<Movie>>& movies,
    const string& cast) {



    std::vector<std::shared_ptr<Movie>> results = movies;

    std::sort(results.begin(), results.end(),compareMovies);

    return results;
}


