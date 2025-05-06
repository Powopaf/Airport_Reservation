#include "query/query.h"
#include <cstring>
#include <vector>
#include "airlines/airline.h"
#include <iostream>

const char data_flights[16] = "flights/flights";

int main() {
    std::vector<Airline> flights = parser(data_flights);
    for (int i = 0; i < flights.size(); i++) {
        flights[i].display();
    }
    return EXIT_SUCCESS;
}
