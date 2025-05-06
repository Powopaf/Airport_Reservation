#include "query/query.h"
#include <cstring>
#include <vector>
#include "airlines/airline.h"
#include "airlines/booking.h"

const char data_flights[16] = "flights/flights";

int main() {
    std::vector<Airline> flights = parser(data_flights);
    /*
    for (int i = 0; i < flights.size(); i++) {
        flights[i].display();
    }
    */
    add(flights, 2, 123);
    check(flights, 123);
    remove(flights, 1, 123);
    check(flights, 123);
    //check(flights);
    return EXIT_SUCCESS;
}
