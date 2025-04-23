#include <string>
#include <vector>
#include "airline.h"

void add(std::vector<Airline> flights, int passengers, int id) {
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i].get_id() == id) {
            if (flights[i].get_nb_passengers() + passengers <= flights[i].get_limit_passengers()) {
               flights[i].set_nb_paasengers(passengers);
            }
        break;
        }
    }
}

void remove(std::vector<Airline> flights, int passengers, int id) {
    for (int i = 0; i < flights.size(); i++) {
        if (flights[i].get_id() == id) {
            if (flights[i].get_nb_passengers() - passengers >= 0) {
                flights[i].set_nb_paasengers(-passengers);
            }
            break;
        }
    }
}

void check(std::vector<Airline> flights, int passengers, int id) {
    if (id == -1) {
        for (int i = 0; i < flights.size(); i++) {
            flights[i].display();
        }
    }
    else {
        for (int i = 0; i < flights.size(); i++) {
            if (flights[i].get_id() == id) {
                flights[i].display();
                break;
            }
        }
    }
}

void save(std::string path, std::vector<Airline> flights) {

}
