#include <iostream>
#include <string>
#include <vector>
#include "fstream"
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

void check(std::vector<Airline> flights, int id, std::string time, std::string dest) {
    long unsigned int i = 0;
    if (id != -1) {
        while (i < flights.size() && flights[i].get_id() != id) {
            i++;
        }
        if (i >= flights.size()) {
            std::cout << "No flight with id: " << id << std::endl;
            return;
        }
        flights[i].display();
    }
    else if (!time.empty()) {
        for (long unsigned int i = 0; i < flights.size(); i++) {
            if (flights[i].get_time() == time) {
                flights[i].display();
            }
        }
    }
    else {
        for (long unsigned int i = 0; i < flights.size(); i++) {
            if (flights[i].get_destination() == dest) {
                flights[i].display();
            }
        }
    }
}

void save(std::string path, std::vector<Airline> flights) {
    std::ofstream ofs(path);
    if (!ofs) {
        std::cerr << "Error: could not open \"" << path << "\" to save data" << std::endl;
        return;
    }
    for (const auto &f : flights) {
        ofs
          << f.get_name()             << ' '
          << f.get_id()               << ' '
          << f.get_nb_passengers()    << ' '
          << f.get_limit_passengers() << ' '
          << f.get_time()             << ' '
          << f.get_destination()
          << '\n';
    }
}
