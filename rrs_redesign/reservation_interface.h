
#ifndef RRS_REDESIGN_RESERVATION_INTERFACE_H
#define RRS_REDESIGN_RESERVATION_INTERFACE_H

#include "station.h"
#include "functionality.h"

class reservation_interface{
    std::vector<Station*> stations;
    functionality* train_facilities;

public:

    reservation_interface(){

        for(int i =0; i<5; i++){
            stations.push_back(new Station());
        }

    }


    void display_trains_menu();
    void display_functions_menu();

};


#endif //RRS_REDESIGN_RESERVATION_INTERFACE_H
