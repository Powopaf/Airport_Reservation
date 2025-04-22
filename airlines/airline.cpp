#include "airline.h"
#include <string>

Airline::Airline(std::string name, int id, int nb_passengers, int limit_passengers) 
    : name(name), id(id), nb_passengers(nb_passengers), limit_passengers(limit_passengers)
{}

std::string Airline::get_name() const {
    return name;
}

int Airline::get_id() const {
    return id;
}

int Airline::get_nb_passengers() const {
    return nb_passengers;
}

int Airline::get_limit_passengers() const {
    return limit_passengers;
}

void Airline::set_nb_paasengers(int passenger) {
    nb_passengers = passenger;
}

void Airline::display() {
    // TODO write display function
}
