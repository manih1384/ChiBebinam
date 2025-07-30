#pragma once
#include <string>

const std::string ERROR_USAGE_MSG = "Usage: ./ChiBebinam <users.csv> <movies.csv>";
const std::string PROMPT = "> ";
const std::string ERROR_PREFIX = "Error: ";
const std::string UNKOWN_ERROR_PREFIX = "Unknown Error: ";
const int REQUIRED_ARG_COUNT = 3;
const int USERS_PATH_INDEX = 1;
const int MOVIES_PATH_INDEX = 2;
const std::string CAST_RECOMMENDATION_FORMAT = "cast_recommendation <?Username> <Cast>";
const std::string GENRE_RECOMMENDATION_FORMAT = "genre_recommendation <?Username> <Genre>";
const std::string GENRE_RECOMMENDATION = "genre_recommendation";
const std::string CAST_RECOMMENDATION = "cast_recommendation";
const std::string NO_MOVIE_FOUND = "No suitable movies were found."; 