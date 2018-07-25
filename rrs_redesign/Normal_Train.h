
#ifndef RRS_REDESIGN_NORMAL_TRAIN_H
#define RRS_REDESIGN_NORMAL_TRAIN_H

#include "Train.h";
#include "costs.h"


class Normal_Train : Train, costs{
private:
    static int Normal_Train_ID = 0;

public:
    Normal_Train():Train("NT",3,2) {
        Normal_Train_ID++;
        get_train_type();
    }

    void set_train_name();
    std::string get_train_name();

    std::string get_train_type();
    int get_bogie_count();
    int get_seat_count_per_bogie();

    void construct_train();
    std::string** get_constructed_train();

    std::string ticket_cost();
    std::string cancellation_cost();
    std::string food_cost();
};


#endif //RRS_REDESIGN_NORMAL_TRAIN_H
