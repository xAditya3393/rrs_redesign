

#include "person.h"
#include "person_originator.h"

#ifndef RRS_REDESIGN_FILE_OPERATIONS_H
#define RRS_REDESIGN_FILE_OPERATIONS_H


class file_operations {
private:
    std::string file_path;
    void take_user_file_path();


public:

    void delete_file_contents();
    std::string get_file_path();
    std::vector<std::string> get_parsed_string(std::string);
    std::string file_input_for_details();
    void file_output_for_ticket(person_originator* details);
    void reading_ticket_for_confirmation();

};


#endif //RRS_REDESIGN_FILE_OPERATIONS_H
