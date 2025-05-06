#include "airline.h"
#include <iostream>
#include <string>

Airline::Airline(std::string name, int id, int nb_passengers, int limit_passengers,
        std::string destination, std::string time) 
    : name(name), id(id), nb_passengers(nb_passengers),
    limit_passengers(limit_passengers),
    destination(destination), time(time)
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

std::string Airline::get_destination() const {
    return destination;
}

std::string Airline::get_time() const {
    return time;
}

void Airline::set_nb_pasengers(int passenger) {
    nb_passengers = passenger;
}

void Airline::display() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "ID: " << id << std::endl;
    std::cout << "Number of passengers: " << nb_passengers << "/" << limit_passengers << std::endl;
    std::cout << "Destination: " << destination << std::endl;
    std::cout << "Departure: " << time << std::endl;
}
