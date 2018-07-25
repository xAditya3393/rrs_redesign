#include "station.h"
#include <iostream>
#include <vector>



void Station::set_station_name(){
    station_name = "Station " + Station::Station_ID;
}

std::string Station::get_station_name(){
    return station_name;
}

void Station::insert_normal_train() {
    Train* create_train = create_train->create_train_object("NT");
    Normal_trains.push_back(create_train);

}

void Station::insert_express_train() {
    Train* create_train = create_train->create_train_object("ET");
    Express_trains.push_back(create_train);

}

void Station::display_normal_trains() {
    for(Train* NT: Normal_trains)
    {
        std::cout << NT->get_train_name() << "\n";
    }
}

void Station::display_express_trains() {
    for(Train* ET: Express_trains)
    {
        std::cout << ET->get_train_name() << "\n";
    }
}

void Station::display_all_trains() {
    std::cout << "Normal Trains: " << "\n";
    display_normal_trains();
    std::cout << "Express Trains: " << "\n";
    display_express_trains();
}