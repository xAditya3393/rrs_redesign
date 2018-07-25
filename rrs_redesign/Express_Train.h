#ifndef RRS_REDESIGN_EXPRESS_TRAIN_H
#define RRS_REDESIGN_EXPRESS_TRAIN_H

#include "Train.h";
#include "costs.h";

class Express_Train : Train,costs{

private:
    static int Express_Train_ID = 0;

public:
    Express_Train():Train("ET",3,3) {
        Express_Train_ID++;
        set_train_name();
    }

    void set_train_name();
    std::string get_train_name();

    std::string get_train_type();
    int get_bogie_count();
    int get_seat_count_per_bogie();

    void construct_train();
    std::string** Express_Train::get_constructed_train();

    std::string ticket_cost();
    std::string cancellation_cost();
    std::string food_cost();

};


#endif //RRS_REDESIGN_EXPRESS_TRAIN_H
