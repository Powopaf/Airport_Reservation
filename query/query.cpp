#include "query.h"
#include <array>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <string>
#include "../booking/airline.h"

int stringToInt(std::string s) {
    int res = 0;
    for (char c : s) {
       res *= 10;
       switch (c) {
           case '0':
               break;
           case '1':
               res += 1;
               break;
           case '2':
               res += 2;
               break;
           case '3':
               res += 3;
               break;
           case '4':
               res += 4;
               break;
           case '5':
               res += 5;
               break;
           case '6':
               res += 6;
               break;
           case '7':
               res += 7;
               break;
           case '8':
               res += 8;
               break;
           case '9':
               res += 9;
               break;
           default :
               std::cout << "Error in stringToInt" << std::endl;
       }
    }
    return res;
}


std::array<std::string, 4> parseline(std::string line) {
    std::array<std::string, 4> res;
    std::istringstream iss(line);
    std::string name, id, ratio;
    if (!(iss >> name >> id >> ratio)) {
        throw std::invalid_argument("Invalid format in line: " + line);
    }
    auto slash = ratio.find('/');
    if (slash == std::string::npos) {
        throw std::invalid_argument("Invalid format in line: " + line);
    }
    std::string nb1 = ratio.substr(0, slash);
    std::string nb2 = ratio.substr(slash + 1);
    res[0] = name;
    res[1] = id;
    res[2] = nb1;
    res[3] = nb2;
    return res;
}



std::vector<Airline> parser(const std::string path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Cannot open file: " + path);
    }
    std::vector<Airline> res;
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) {
            continue;
        }
        std::array<std::string, 4> parts = parseline(line);
        res.push_back(Airline(parts[0],
                    stringToInt(parts[1]),
                    stringToInt(parts[2]),
                    stringToInt(parts[3])));
    }
    return res;
}
