
#include "singleton.h"
#include "reservation_interface.h"

/*

class Station
{
    string station_name;
    std::vector<Train*> Normal_trains;
    std::vector<Train*> Express_trains;

    insert_train();

    display_normal_trains();
    display_express_trains();
    display_all_trains();
};

//pure virtual
class Train{
    string train_name;
    string train_type;
    string[][] constructed_train;
    //string train_route;
    int bogie_count;
    int seat_count_per_bogie;

    //factory method
    create_train_object(train_type_value);
    construct_train();
};

//pure virtual
class costs{
    ticket_cost();
    cancellation_cost();
    food_cost();
};


class person_details{
    string name;
    string gender;
    string food_choice;

};

class file_operations {
    file_input_for_details();
    file_output_for_ticket();
    reading_ticket_for_confirmation();

};

//pure virtual
class functionality{
    cancel_or_recover_ticket; //memento pattern
    availability; //show_train();
    reservation; //preference(), giveseat();
    cancellation; //remove();
};




// --memento pattern goes here--


class Normal_Train : Train,costs{

};
class Express_Train : Train,costs{
};

//facade method
class reservationInterface{
    std::vector<Station*> stations;

    //coach selection from availability
    display_select_stations();
    display_select_trains();

};

*/


int main() {

    reservation_interface* facade_interface;

    facade_interface->display_trains_menu();
    facade_interface->display_functions_menu();

    return 0;
}

