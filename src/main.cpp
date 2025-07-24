#include "ChiBebinam.hpp"
#include "AppException.hpp"
#include "utils/Constants.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
    try {
        ChiBebinam app(argc, argv);
        app.run();
    } catch (const AppException& e) {
        std::cerr << ERROR_PREFIX << e.getMessage() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << ERROR_PREFIX << e.what() << std::endl;
        return 2;
    }
    return 0;
}
