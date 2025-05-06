#include "query/query.h"
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include "airlines/airline.h"
#include "airlines/booking.h"

const char data_flights[16] = "flights/flights";
const std::string start_message = "Enter:\n0 to exit,\n1 to add a flight,\n2 to book a flight,\n3 to unbook a flight,\n4 to look at a flight.\n";

Airline add_flight() {
    std::string name;
    std::string id;
    int nb_passengers = 0;
    std::string limit_passengers;
    std::string destination;
    std::string time;
    std::cout << "Enter Name of the compagny: ";
    std::cin >> name;
    std::cout << "Enter the id of the flight: ";
    std::cin >> id;
    std::cout << "Enter the limit of passengers: ";
    std::cin >> limit_passengers;
    std::cout << "Enter the destination: ";
    std::cin >> destination;
    std::cout << "Enter the departure time: ";
    std::cin >> time;
    return Airline(name, stringToInt(id),
            nb_passengers, stringToInt(limit_passengers),
            destination, time);
}

int main() {
    std::vector<Airline> flights = parser(data_flights);
    char exit = 0;
    std::string user;
    while (exit == 0) {
        std::cout << start_message;
        std::cin >> user;
        if (user == "0") {
            exit = -1;
        }
        else if (user == "1") {
            flights.push_back(add_flight());
        }
        else if (user == "2") {
            std::string id;
            std::string passengers;
            std::cout << "Enter flight id: " << std::endl;
            std::cin >> id;
            std::cout << "Enter number of passengers: " << std::endl;
            std::cin >> passengers;
            add(flights, stringToInt(passengers), stringToInt(id));
        }
        else if (user == "3") {
            std::string id;
            std::string passengers;
            std::cout << "Enter flight id: " << std::endl;
            std::cin >> id;
            std::cout << "Enter number of passengers: " << std::endl;
            std::cin >> passengers;
            remove(flights, stringToInt(passengers), stringToInt(id));
        }
        else if (user == "4") {
            std::string way;
            std::cout << "Choose the way you will check the flights:\n1 for id,\n2 for time of arrival,\n3 for destination\n";
            std::cin >> way;
            if (way == "1") {
                std::cout << "Enter the id:" << std::endl;
                std::cin >> way;
                check(flights, stringToInt(way));
            }
            else if (way == "2") {
                std::cout << "Enter the time of arrival: " << std::endl;
                std::cin >> way;
                check(flights, -1, way);
            }
            else if (way == "3") {
                std::cout << "Enter the destination: " << std::endl;
                std::cin >> way;
                check(flights, -1, "", way);
            }
            else {
                std::cout << "Wrong choice" << std::endl;
            }
        }
        else {
            std::cout << "Wrong name" << std::endl;
        }
    }
    save(data_flights, flights);
    return EXIT_SUCCESS;
}
