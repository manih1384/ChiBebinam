#include "ChiBebinam.hpp"
#include "utils/CsvParser.hpp"
#include "utils/Constants.hpp"
#include "AppException.hpp"
#include <iostream>
#include <string>

ChiBebinam::ChiBebinam(Database& database)
    : db(database) {}



void ChiBebinam::run() {
    std::cout << PROMPT;
    std::string input;

    while (std::getline(std::cin, input)) {
        try {
            if (input == "exit" || input == "quit") break;
            processCommand(input);
        } catch (const AppException& ex) {
            std::cerr << ERROR_PREFIX << ex.getMessage() << std::endl;
        } catch (const std::exception& ex) {
            std::cerr << UNKOWN_ERROR_PREFIX<< ex.what() << std::endl;
        }
        std::cout << PROMPT;
    }
}

void ChiBebinam::processCommand(const std::string& input) {
    auto tokens = CsvParser::split(input, ' ');

    if (tokens.empty()) {
        throw InvalidArguments();
    }

    const std::string& cmd = tokens[0];

    if (cmd == GENRE_RECOMMENDATION) {
        handleGenreRecommendation(tokens);
    } else if (cmd == CAST_RECOMMENDATION) {
        handleCastRecommendation(tokens);
    } else {
        throw UnknownCommand(cmd);
    }
}

void ChiBebinam::handleGenreRecommendation(const std::vector<std::string>& tokens) {
    if (tokens.size() == 3) {
        std::string username = tokens[1];
        std::string genre = tokens[2];

        const User& user = db.getUserByName(username);
        const std::vector<std::shared_ptr<Movie>>& movies = db.getAllMovies();

        std::vector<std::shared_ptr<Movie>> results = genreRec.recommend(user, movies, genre);

        handleOutput(results, 3);
    }

    else if (tokens.size() == 2) {
        std::string genre = tokens[1];
        const std::vector<std::shared_ptr<Movie>>& movies = db.getAllMovies();

        std::vector<std::shared_ptr<Movie>> results = genreRec.recommend(movies, genre);
        handleOutput(results, 3);
    }
    
    else {
        throw InvalidCommandFormat(GENRE_RECOMMENDATION_FORMAT);
    }
}



void ChiBebinam::handleCastRecommendation(const std::vector<std::string>& tokens) {
    if (tokens.size() == 3) {
        // castRec.recommend(tokens[1], tokens[2]);
    } else if (tokens.size() == 2) {
        // castRec.recommend("", tokens[1]);
    } else {
        throw InvalidCommandFormat(CAST_RECOMMENDATION_FORMAT);
    }
}


void ChiBebinam::handleOutput(const std::vector<std::shared_ptr<Movie>>& movies, int count) {
    if (movies.empty()) {
        std::cout << NO_MOVIE_FOUND << std::endl;
        return;
    }

    for (int i = 0; (i < movies.size() && i < count); i++) {
        const std::shared_ptr<Movie>& movie = movies[i];


        std::cout << (i + 1) << ". " << movie->getName() << ": "
                  << movie->getDirector() << " ("
                  << movie->getImdbScore() << ")" << std::endl;
    }
}
