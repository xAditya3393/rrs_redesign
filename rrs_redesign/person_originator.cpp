
#include "person_originator.h"
#include <vector>

std::string person_originator::get_current_name(){
    return this->current_name;
}
std::string person_originator::get_current_age(){
    return this->current_age;
}
std::string person_originator::get_current_gender(){
    return this->current_gender;
}
std::string person_originator::get_current_food_choice(){
    return this->current_food_choice;
}

void person_originator::set_current_name(std::string _name){
    this->current_name = _name;
}
void person_originator::set_current_age(std::string _age){
    this->current_age = _age;
}
void person_originator::set_current_gender(std::string _gender){
    this->current_gender = _gender;
}
void person_originator::set_current_food_choice(std::string _food_choice){
    this->current_food_choice = _food_choice;
}


Person* person_originator::create_person(){

    file_operations* get_person_details;
    std::string person_details = get_person_details->file_input_for_details();
    std::vector<std::string> result = get_person_details->get_parsed_string(person_details);

    return new Person(result[0], result[1], result[2], result[3]);

}

void person_originator::restore_person(Person* saved_state_person) {

    this->current_name = saved_state_person->get_current_name();
    this->current_age =  saved_state_person->get_current_age();
    this->current_gender = saved_state_person->get_current_gender();
    this->current_food_choice = saved_state_person->get_current_food_choice();

}