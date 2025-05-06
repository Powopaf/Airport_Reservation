#include "query.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "../airlines/airline.h"

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

std::vector<Airline> parser(const std::string path) {
    std::vector<Airline> res;
    std::ifstream file(path);
    if (!file) {
        std::cout << "No file: " << path << std::endl;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<std::string> tokens;
        std::string words;
        while (iss >> words) {
            tokens.push_back(words);
        }
        res.push_back(Airline(tokens[0], stringToInt(tokens[1]), stringToInt(tokens[2]),
                    stringToInt(tokens[3]), tokens[5], tokens[4]));
    }
    return res;
}
