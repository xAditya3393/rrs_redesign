
#include "person_caretaker.h"

void person_caretaker::create_and_save_person_state(){

    Person* save_person = originator.create_person();
    person_saved_states.push_back(save_person);
}

void person_caretaker::revert_person_state(int saved_state_number){
    if(saved_state_number < person_saved_states.size()){
        originator.restore_person(person_saved_states[saved_state_number]);
    }
}

