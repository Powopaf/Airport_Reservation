#ifndef BOOKING_H
#define BOOKING_H

#include <string>
#include <vector>
#include "airline.h"

void add(std::vector<Airline>& flights, int passengers, int id);
void remove(std::vector<Airline>& flights, int passengers, int id);
void check(std::vector<Airline> flights, int id=-1, std::string time="", std::string dest="");
void save(std::string path, std::vector<Airline> flights);

#endif
