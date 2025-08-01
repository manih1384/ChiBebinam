#ifndef ERROR_HPP
#define ERROR_HPP
#include <string>
#include "utils/Constants.hpp"

class AppException {
private:
    std::string message;
public:
    explicit AppException(const std::string& msg) : message(msg) {}
    const std::string& getMessage() const { return message; }
};

class InvalidArguments : public AppException {
public:
    InvalidArguments()
        : AppException(ErrorMessage::INVALID_ARGS) {}
};

class FileLoadError : public AppException {
public:
    explicit FileLoadError(const std::string& filename)
        : AppException(ErrorMessage::FILE_LOAD + filename) {}
};

class CsvRowSizeMismatch : public AppException {
public:
    CsvRowSizeMismatch()
        : AppException(ErrorMessage::MOVIE_CSV_MISMATCH) {}
};

class InvalidImdbScore : public AppException {
public:
    InvalidImdbScore()
        : AppException(ErrorMessage::INVALID_IMDB) {}
};

class InvalidGenreString : public AppException {
public:
    InvalidGenreString(const std::string& genre)
        : AppException(ErrorMessage::INVALID_GENRE + genre) {}
};

class InvalidRatingString : public AppException {
public:
    InvalidRatingString(const std::string& input)
        : AppException(ErrorMessage::INVALID_RATING + input) {}
};

class RatingMismatchError : public AppException {
public:
    RatingMismatchError(const std::string& username)
        : AppException(ErrorMessage::RATING_MISMATCH + username) {}
};

class UserNotFound : public AppException {
public:
    UserNotFound(const std::string& username)
        : AppException(ErrorMessage::USER_NOT_FOUND + username) {}
};

class MovieNotFound : public AppException {
public:
    MovieNotFound(const std::string& movieName)
        : AppException(ErrorMessage::MOVIE_NOT_FOUND + movieName) {}
};

class MalformedUserRow : public AppException {
public:
    MalformedUserRow()
        : AppException(ErrorMessage::MALFORMED_USER) {}
};

class UnknownCommand : public AppException {
public:
    UnknownCommand(const std::string& cmd)
        : AppException(ErrorMessage::UNKNOWN_COMMAND + cmd) {}
};

class InvalidCommandFormat : public AppException {
public:
    InvalidCommandFormat(const std::string& usage)
        : AppException(ErrorMessage::INVALID_COMMAND_FORMAT + usage) {}
};

#endif
