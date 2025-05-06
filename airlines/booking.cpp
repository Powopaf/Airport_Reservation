#include <iostream>
#include <string>
#include <vector>
#include "airline.h"

void add(std::vector<Airline>& flights, int passengers, int id) {
    long unsigned int i = 0;
    while (i < flights.size() && flights[i].get_id() != id) {
        i++;
    }
    if (i >= flights.size()) {
        std::cout << "Flight don't exist" << std::endl;
    }
    else {
        auto& f = flights[i];
        if (f.get_nb_passengers() + passengers <= f.get_limit_passengers()) {
            f.set_nb_pasengers(passengers);
            std::cout << "Added " << passengers << std::endl;
        }
        else {
            std::cout << "Not enought space in the flight" << std::endl;
        }
    }
}

void remove(std::vector<Airline>& flights, int passengers, int id) {
    long unsigned int i = 0;
    while (i < flights.size() && flights[i].get_id() != id) {
        i++;
    }
    if (i >= flights.size()) {
        std::cout << "Flight don't exist" << std::endl;
    }
    else {
        auto& f = flights[i];
        if (f.get_nb_passengers() - passengers >= 0) {
            f.set_nb_pasengers(-passengers);
            std::cout << "Remove the passengers" << std::endl;
        }
        else {
            std::cout << "Flight is empty" << std::endl;
        }
    }
}

void check(std::vector<Airline> flights, int id) {
    if (id == -1) {
        for (long unsigned int i = 0; i < flights.size(); i++) {
            flights[i].display();
        }
    }
    else {
        for (long unsigned int i = 0; i < flights.size(); i++) {
            if (flights[i].get_id() == id) {
                flights[i].display();
                break;
            }
        }
    }
}

void save(std::string path, std::vector<Airline> flights) {

}
