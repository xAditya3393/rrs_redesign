
#include "singleton.h"
#include "functionality.h"
#include "person_caretaker.h"
#include <iostream>
#include <fstream>

void functionality::availability(Train* train) {

    std::string** total_train = train->get_constructed_train();

    for(int i=0; i < train->get_bogie_count() ; i++)
    {
        for(int j=0; j<train->get_seat_count_per_bogie(); j++)
        {
            std::cout <<  total_train[i][j] <<" ";
        }

        std::cout <<"\n";
    }

}


void functionality::count_seat_types(Train* train) {

    std::string** total_train = train->get_constructed_train();

    for(int i=0; i<train->get_bogie_count(); i++)
    {
        for(int j=0; j<train->get_seat_count_per_bogie(); j++)
        {
            if((i == 0 || i == train->get_bogie_count() -1) && (total_train[i][j] ==""))
            {
                functionality::window_seats++;
            }
            else if ((i != 0 || i != train->get_bogie_count() -1) && (total_train[i][j] ==""))
            {
                functionality::non_window_seats++;
            }
        }
    }

    std::cout << "\n The seats are : Window = " << window_seats << " , Non-Window =  " <<non_window_seats <<"\n";
}


void functionality::reservation(Train *train, std::string seat_preference) {


    current_date_time* ticket_time = current_date_time::create_instance();

    if((seat_preference == "window" && window_seats > 0) ||
        (seat_preference == "non_window" && non_window_seats > 0 ))
    {
        std::vector<int> seat_num = get_seat(train, seat_preference);

        std::cout << "Seat Number : " << std::to_string(seat_num[0]) <<" "<< std::to_string(seat_num[1]) ;
        std::cout << "\n Reservation done at : ";
        ticket_time->time_output();
        std::cout << std::endl;
    }
}


std::vector<int> functionality::get_seat(Train* train, std::string seat_preference) {

    std::string** complete_train = train->get_constructed_train();
    std::vector<int> seat;

    if(seat_preference == "window")
    {
        for(int i=0; i<train->get_bogie_count(); i++)
        {
            if(i == 0 || i == train->get_bogie_count() -1)
            {
                for(int j=0; j<train->get_seat_count_per_bogie(); j++)
                {
                    if(complete_train[i][j] == "")
                    {
                        functionality::window_seats--;

                        seat.push_back(i);
                        seat.push_back(j);
                    }
                }
            }
            else
                continue;

        }
    }
    else if(seat_preference == "non_window")
    {
        for(int i=0; i<train->get_bogie_count(); i++)
        {
            if (i != 0 || i != train->get_bogie_count() -1){

                for(int j=0; j<train->get_seat_count_per_bogie(); j++)
                {
                    if (complete_train[i][j] == "")
                    {
                        functionality::non_window_seats--;

                        seat.push_back(i);
                        seat.push_back(j);
                    }
                }
            }
            else
                continue;

        }


    }

    return seat;

}

void functionality::cancellation(Train* train, std::vector<int> seat) {

    cancel_ticket();

    std::string** complete_train = train->get_constructed_train();
    complete_train[seat[1]][seat[2]] = "";

    current_date_time* ticket_time = current_date_time::create_instance();
    std::cout << "\n Cancelled at : ";
    ticket_time->time_output();
    std::cout << std::endl;

    changing_file_contents->delete_file_contents();

}

void functionality::recover_cancelled_ticket(Train* train, std::vector<int> seat, person_originator* details){

    recover_ticket();

    std::string** complete_train = train->get_constructed_train();
    complete_train[seat[1]][seat[2]] = "AP"; //Person Initials

    current_date_time* ticket_time = current_date_time::create_instance();
    std::cout << "\n Recovered at : ";
    ticket_time->time_output();
    std::cout << std::endl;

    changing_file_contents->file_output_for_ticket(details);

}


void functionality::cancel_ticket(){

    person_recovery->create_and_save_person_state();

}


void functionality::recover_ticket(){

    //user enters the state to which details have to recover from
    //For test purposes using 1
    person_recovery->revert_person_state(1);

}

