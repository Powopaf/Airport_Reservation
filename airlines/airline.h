#ifndef AIRLINE_H
#define AIRLINE_H

#include <string>

class Airline {
    private:
        std::string name;
        int id;
        int nb_passengers;
        int limit_passengers;
        std::string destination;
        std::string time;  
    public:
        Airline(std::string name, int id, int nb_passengers, int limit_passengers, 
                std::string destination, std::string time);
        std::string get_name() const;
        int get_id() const;
        int get_nb_passengers() const;
        int get_limit_passengers() const;
        std::string get_destination() const;
        std::string get_time() const;
        void set_nb_pasengers(int passenger=1);
        void display();
};

#endif
