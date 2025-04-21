#include "booking/airline.h"
#include "query/query.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<Airline> flights = parser("flights/flights");
    std::cout << flights[0].get_name() << std::endl;
    std::cout << flights[0].get_id() << std::endl;
    std::cout << flights[0].get_nb_passengers() << std::endl;
    std::cout << flights[0].get_limit_passengers() << std::endl;
    std::cout << flights[1].get_name() << std::endl;
    std::cout << flights[1].get_id() << std::endl;
    std::cout << flights[1].get_nb_passengers() << std::endl;
    std::cout << flights[1].get_limit_passengers() << std::endl;
    std::cout << flights[2].get_name() << std::endl;
    std::cout << flights[2].get_id() << std::endl;
    return EXIT_SUCCESS;
}
