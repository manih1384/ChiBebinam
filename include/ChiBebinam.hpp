#ifndef CHIBEBINAM_HEADER
#define CHIBEBINAM_HEADER
#include "Database.hpp"

class ChiBebinam {
public:
    ChiBebinam(Database& database);
    void run();

private:
    Database& db;

    void handleCommand();
};

#endif
