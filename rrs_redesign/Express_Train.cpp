
#include "Express_Train.h";

void Express_Train::set_train_name(){
    train_name = "Express_Train" + std::to_string(Express_Train_ID);
}

std::string Express_Train::get_train_name(){
    return train_name;
}

std::string Express_Train::get_train_type(){
    return train_type;
}

int Express_Train::get_bogie_count(){
    return bogie_count;
}

int Express_Train::get_seat_count_per_bogie(){
    return seat_count_per_bogie;
}

void Express_Train::construct_train(){
    constructed_train = new std::string*[bogie_count];

    for(int i=0; i<bogie_count; i++)
    {
        constructed_train[i] = new std::string[seat_count_per_bogie];
    }

}

std::string** Express_Train::get_constructed_train() {
    return constructed_train;
}

std::string Express_Train::ticket_cost() {
    return "$50";
}

std::string Express_Train::cancellation_cost() {
    return "$50";
}
std::string Express_Train::food_cost() {
    return "$50";
}
