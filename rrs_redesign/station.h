#ifndef RRS_REDESIGN_STATION_H
#define RRS_REDESIGN_STATION_H

#include <string>
#include <vector>
#include "Train.h"

class Station
{
private:
    std::string station_name;
    std::vector<Train*> Normal_trains;
    std::vector<Train*> Express_trains;

    static int Station_ID = 0;

public:

    Station(){

        Station_ID++;

        for(int i=0; i<5; i++) {
            this->insert_normal_train();
        }

        for(int i=0; i<5; i++) {
            this->insert_express_train();
        }

        set_station_name();
    }


    void set_station_name();
    std::string get_station_name();

    void insert_normal_train();
    void insert_express_train();

    void display_normal_trains();
    void display_express_trains();
    void display_all_trains();
};


#endif //RRS_REDESIGN_STATION_H
