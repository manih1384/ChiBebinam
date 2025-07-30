#ifndef SCORED_MOVIE_HEADER
#define SCORED_MOVIE_HEADER

#include <memory>
#include <string>
#include "entities/Movie.hpp"

struct ScoredMovie {
    std::shared_ptr<Movie> movie;
    float score;


    ScoredMovie(std::shared_ptr<Movie> m, float s)
        : movie(m), score(s) {}

    bool operator<(const ScoredMovie& other) const {

        if (score != other.score)
            return score > other.score; 

        if (movie->getImdbScore() != other.movie->getImdbScore())
            return movie->getImdbScore() > other.movie->getImdbScore(); 
            
        return movie->getName() < other.movie->getName(); 
    }
};

#endif
