#include "recommender/GenreRecommender.hpp"
#include "recommender/ScoredMovie.hpp"
#include <algorithm>
#include <iostream>

std::vector<std::shared_ptr<Movie>> GenreRecommender::recommend(
    const User& user,
    const std::vector<std::shared_ptr<Movie>>& movies,
    const std::string& genreStr
) {



    Genre genreEnum = stringToGenre(genreStr);
    std::vector<ScoredMovie> scoredMovies;

    for (const auto& movie : movies) {

        if (movie->getGenre() != genreEnum || user.hasWatched(movie)) continue;

        float score = calculateScore(user, movie);

        scoredMovies.push_back({movie, score});

    }

    std::sort(scoredMovies.begin(), scoredMovies.end());

    std::vector<std::shared_ptr<Movie>> results;
    for (const auto& entry : scoredMovies) {
        results.push_back(entry.movie);
    }

    return results;
}


float GenreRecommender::calculateScore(
    const User& user,
    const std::shared_ptr<Movie>& movie
) {


    float score = 0;

    score += 0.5*calculateDirectorEffect(user, movie);
    score += 0.6*calculateCastEffect(user, movie);
    score += 0.7*static_cast<float>(movie->getImdbScore());

    return score;
}


float GenreRecommender::calculateDirectorEffect(
    const User& user,
    const std::shared_ptr<Movie>& movie
) {
    const std::string& desiredDirector = movie->getDirector();

    for (const auto& watched : user.getWatchedMovies()) {
        if (watched.movie->getDirector() == desiredDirector) {
            if (watched.rating == Rating::Perfect) {
                return 10;
            } else if (watched.rating == Rating::Average) {
                return 5;
            } else if (watched.rating == Rating::Poor) {
                return -1;
            }
        }
    }

    return 0;
}


float GenreRecommender::calculateCastEffect(
    const User& user,
    const std::shared_ptr<Movie>& movie
) {
    const std::string& targetCast = movie->getCast();

    for (const auto& watched : user.getWatchedMovies()) {
        const std::string& watchedCast = watched.movie->getCast();

        if (targetCast == watchedCast) {
            if (watched.rating == Rating::Perfect) {
                return 7;
            } else if (watched.rating == Rating::Average) {
                return 4;
            } else if (watched.rating == Rating::Poor) {
                return -2;
            }
        }
    }

    return 0;
}




std::vector<std::shared_ptr<Movie>> GenreRecommender::recommend(
    const std::vector<std::shared_ptr<Movie>>& movies,
    const std::string& genreStr
) {
    Genre genreEnum = stringToGenre(genreStr);
    std::vector<ScoredMovie> scoredMovies;

    for (const std::shared_ptr<Movie>& movie : movies) {
        if (movie->getGenre() != genreEnum)
            continue;

        float score = static_cast<float>(movie->getImdbScore());
        scoredMovies.push_back({movie, score});
    }

    std::sort(scoredMovies.begin(), scoredMovies.end());

    std::vector<std::shared_ptr<Movie>> results;
    for (const ScoredMovie& entry : scoredMovies) {
        results.push_back(entry.movie);
    }

    return results;
}
