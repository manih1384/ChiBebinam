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
    const vector<User>& /* unused */,
    const vector<shared_ptr<Movie>>& movies,
    const string& cast) {

    // // Filter movies by cast
    // vector<shared_ptr<Movie>> candidates = filterMoviesByCast(movies, cast);
    
    // // Sort and return top 2
    // sortMoviesByImdbAndName(candidates);
    // return candidates.size() > 2 ? 
    //     vector<shared_ptr<Movie>>{candidates[0], candidates[1]} : 
    //     candidates;
}


vector<shared_ptr<Movie>> CastRecommender::filterMoviesByCast(
    const vector<shared_ptr<Movie>>& movies,
    const string& cast) const {

    vector<shared_ptr<Movie>> result;
    for (const auto& movie : movies) {
        if (movie->getCast() == cast) {
            result.push_back(movie);
        }
    }
    return result;
}

