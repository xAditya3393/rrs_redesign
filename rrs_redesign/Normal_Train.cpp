
#include "Normal_Train.h";

void Normal_Train::set_train_name(){
    train_name = "Normal_Train" + std::to_string(Normal_Train_ID);
}


std::string Normal_Train::get_train_name(){
    return train_name;
}


std::string Normal_Train::get_train_type(){
    return train_type;
}


int Normal_Train::get_bogie_count(){
    return bogie_count;
}


int Normal_Train::get_seat_count_per_bogie(){
    return seat_count_per_bogie;
}


void Normal_Train::construct_train(){
    constructed_train = new std::string*[bogie_count];

    for(int i=0; i<bogie_count; i++)
    {
        constructed_train[i] = new std::string[seat_count_per_bogie];
    }

}

std::string** Normal_Train::get_constructed_train() {
    return constructed_train;
}


std::string Normal_Train::ticket_cost() {
    return "$25";
}

std::string Normal_Train::cancellation_cost(){
    return "$25";
}

std::string Normal_Train::food_cost(){
    return "$25";
}

