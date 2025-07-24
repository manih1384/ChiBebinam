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

class MovieNotFound : public AppException {
public:
    MovieNotFound() : AppException("Movie not found") {}
};