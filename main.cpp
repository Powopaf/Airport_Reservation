#include "query/query.h"
#include <cstring>
#include <vector>
#include "airlines/airline.h"
#include "airlines/booking.h"

const char data_flights[16] = "flights/flights";

int main() {
    std::vector<Airline> flights = parser(data_flights);
    check(flights, -1, "", "Paris");
    return EXIT_SUCCESS;
}
