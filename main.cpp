#include "booking/airline.h"
#include "query/query.h"
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

const std::string data_flights = "flights/flights";

int main(int argc, char* argv[]) {
    std::vector<Airline> flights = parser(data_flights);
    if (argc == 4 && std::strcmp(argv[1], "book") == 0) {
        return EXIT_SUCCESS;
    }
    if (argc >= 2 && argc <= 3 && std::strcmp(argv[1], "check")) {
        return EXIT_SUCCESS;
    }
    if (argc == 4 && std::strcmp(argv[1], "cancel")) {
        return EXIT_SUCCESS;
    }
    return EXIT_FAILURE;
}
