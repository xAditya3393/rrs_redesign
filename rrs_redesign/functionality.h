
#ifndef RRS_REDESIGN_FUNCTIONALITY_H
#define RRS_REDESIGN_FUNCTIONALITY_H

#include "Train.h"
#include "file_operations.h"
#include "person_caretaker.h"
#include <vector>

class functionality{

private:
    file_operations* changing_file_contents;
    person_caretaker* person_recovery;
    static int window_seats=0, non_window_seats=0;

    void count_seat_types(Train* train);
    std::vector<int> get_seat(Train* train, std::string seat_preference);


    void cancel_ticket();
    void recover_ticket();
public:

    void availability(Train* train);
    void reservation(Train* train, std::string seat_preference);
    void cancellation(Train* train, std::vector<int> seat);
    void recover_cancelled_ticket(Train* train, std::vector<int> seat, person_originator* details);
};



#endif //RRS_REDESIGN_FUNCTIONALITY_H
