#include "person.h"
#include "person_originator.h"
#include <vector>

#ifndef RRS_REDESIGN_PERSON_CARETAKER_H
#define RRS_REDESIGN_PERSON_CARETAKER_H

class person_caretaker{

    std::vector<Person*> person_saved_states;
    person_originator originator;

public:

    void create_and_save_person_state();
    void revert_person_state(int saved_state_number);

};

#endif //RRS_REDESIGN_PERSON_CARETAKER_H
