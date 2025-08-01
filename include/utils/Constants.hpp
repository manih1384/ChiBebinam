#pragma once
#include <string>


const int REQUIRED_ARG_COUNT = 3;
const int USERS_PATH_INDEX = 1;
const int MOVIES_PATH_INDEX = 2;


const std::string QUIT = "quit";
const std::string GENRE_RECOMMENDATION = "genre_recommandation";
const std::string CAST_RECOMMENDATION = "cast_recommandation";


const std::string GENRE_RECOMMENDATION_FORMAT = "genre_recommandation <?Username> <Genre>";
const std::string CAST_RECOMMENDATION_FORMAT = "cast_recommandation <?Username> <Cast>";


const std::string ERROR_USAGE_MSG = "Usage: ./ChiBebinam <users.csv> <movies.csv>";
const std::string PROMPT = "$ ";
const std::string ERROR_PREFIX = "Error: ";
const std::string UNKOWN_ERROR_PREFIX = "Unknown Error: ";



namespace ErrorMessage {
    const std::string INVALID_ARGS = "Invalid command line arguments";
    const std::string FILE_LOAD = "Failed to load file: ";
    const std::string MOVIE_CSV_MISMATCH = "CSV row size mismatch: expected 5 fields for Movie";
    const std::string INVALID_IMDB = "Invalid IMDb score: must be an integer between 0 and 10";
    const std::string INVALID_GENRE = "Invalid genre string: ";
    const std::string INVALID_RATING = "Invalid rating string: ";
    const std::string RATING_MISMATCH = "Ratings and movies count mismatch for user: ";
    const std::string USER_NOT_FOUND = "User not found: ";
    const std::string MOVIE_NOT_FOUND = "Movie not found: ";
    const std::string MALFORMED_USER = "Malformed user CSV row.";
    const std::string UNKNOWN_COMMAND = "Unknown command: ";
    const std::string INVALID_COMMAND_FORMAT = "Valid Command Format: ";
    const std::string NO_MOVIE_FOUND = "No suitable movies were found.";
}
