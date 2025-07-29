#include <iostream>
#include "ChiBebinam.hpp"
#include "Database.hpp"
#include "AppException.hpp"
#include "utils/Constants.hpp"



int main(int argc, char* argv[]) {
    if (argc < REQUIRED_ARG_COUNT) {
        std::cerr << "Missing path to CSV file.Usage: ./ChiBebinam <users.csv> <movies.csv>" << std::endl;
        return 1;
    }

    try {
        Database db(argv[USERS_PATH_INDEX], argv[MOVIES_PATH_INDEX]);
        ChiBebinam app(db);
        app.run();
    } catch (const AppException& e) {
        std::cerr << ERROR_PREFIX << e.getMessage() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr <<UNKOWN_ERROR_PREFIX<< e.what() << std::endl;
        return 2;
    }
    return 0;
}
