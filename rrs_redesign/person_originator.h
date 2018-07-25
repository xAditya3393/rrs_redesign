#include <string>
#include "Person.h"
#include "file_operations.h"

#ifndef RRS_REDESIGN_PERSON_ORIGINATOR_H
#define RRS_REDESIGN_PERSON_ORIGINATOR_H

class person_originator{

    std::string current_name;
    std::string current_age;
    std::string current_gender;
    std::string current_food_choice;

public:

    std::string get_current_name();

    std::string get_current_age();
    std::string get_current_gender();
    std::string get_current_food_choice();

    void set_current_name(std::string _name);
    void set_current_age(std::string _age);
    void set_current_gender(std::string _gender);
    void set_current_food_choice(std::string _food_choice);


    Person* create_person();

    void restore_person(Person* saved_state_person);


};

#endif //RRS_REDESIGN_PERSON_ORIGINATOR_H
