#pragma once
#include <string>

class AppException {
private:
    std::string message;
public:
    explicit AppException(const std::string& msg) : message(msg) {}
    const std::string& getMessage() const { return message; }
};


class InvalidArguments : public AppException {
public:
    InvalidArguments() : AppException("Invalid command line arguments") {}
};

class FileLoadError : public AppException {
public:
    explicit FileLoadError(const std::string& filename)
        : AppException("Failed to load file: " + filename) {}
};

class UserNotFound : public AppException {
public:
    UserNotFound() : AppException("User not found") {}
};





class CsvRowSizeMismatch : public AppException {
public:
    CsvRowSizeMismatch()
        : AppException("CSV row size mismatch: expected 5 fields for Movie") {}
};

class InvalidImdbScore : public AppException {
public:
    InvalidImdbScore()
        : AppException("Invalid IMDb score: must be an integer between 0 and 10") {}
};

class InvalidGenreString : public AppException {
public:
    InvalidGenreString(const std::string& genre)
        : AppException("Invalid genre string: " + genre) {}
};



class InvalidRatingString : public AppException {
public:
    explicit InvalidRatingString(const std::string& input)
        : AppException("Invalid rating string: " + input) {}
};



class RatingMismatchError : public AppException {
public:
    RatingMismatchError(const std::string& username)
        : AppException("Ratings and movies count mismatch for user: " + username) {}
};

class MovieNotFound : public AppException {
public:
    MovieNotFound(const std::string& movieName)
        : AppException("Movie not found: " + movieName) {}
};

class MalformedUserRow : public AppException {
public:
    MalformedUserRow() : AppException("Malformed user CSV row.") {}
};
