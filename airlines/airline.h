#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>

class Airline {
    private:
        std::string name;
        int id;
        int nb_passengers;
        int limit_passengers;
    public:
        Airline(std::string name, int id, int nb_passengers, int limit_passengers);
        std::string get_name() const;
        int get_id() const;
        int get_nb_passengers() const;
        int get_limit_passengers() const;
        void set_nb_paasengers(int passenger=1);
        void display();
};

#endif
