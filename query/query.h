#ifndef QUERY_H
#define QUERY_H

#include <string>
#include <vector>
#include "../airlines/airline.h"

int stringToInt(std::string s);
std::vector<Airline> parser(std::string path);

#endif
