#pragma once
#include <string>
const std::string QUIT ="quit";
const std::string ERROR_USAGE_MSG = "Usage: ./ChiBebinam <users.csv> <movies.csv>";
const std::string PROMPT = "> ";
const std::string ERROR_PREFIX = "Error: ";
const std::string UNKOWN_ERROR_PREFIX = "Unknown Error: ";
const int REQUIRED_ARG_COUNT = 3;
const int USERS_PATH_INDEX = 1;
const int MOVIES_PATH_INDEX = 2;
const std::string CAST_RECOMMENDATION_FORMAT = "cast_recommandation <?Username> <Cast>";
const std::string GENRE_RECOMMENDATION_FORMAT = "genre_recommandation <?Username> <Genre>";
const std::string GENRE_RECOMMENDATION = "genre_recommandation";
const std::string CAST_RECOMMENDATION = "cast_recommandation";
const std::string NO_MOVIE_FOUND = "No suitable movies were found."; 