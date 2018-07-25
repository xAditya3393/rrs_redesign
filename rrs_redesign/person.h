#ifndef RRS_REDESIGN_PERSON_H
#define RRS_REDESIGN_PERSON_H

#include <string>

class Person{

    std::string name;
    std::string age;
    std::string gender;
    std::string food_choice;

public:
    Person(){

    }

    Person(std::string name, std::string age, std::string gender, std::string food_choice)
    {
        name = this->name;
        age = this->age;
        gender = this->gender;
        food_choice = this->food_choice;
    }


    std::string get_current_name(){
        return this->name;
    }
    std::string get_current_age(){
        return this->age;
    }
    std::string get_current_gender(){
        return this->gender;
    }
    std::string get_current_food_choice(){
        return this->food_choice;
    }

    std::string get_person_details()
    {
        std::cout << "Name : " << this->name << "\n";
        std::cout << "Age : " << this->age << "\n";
        std::cout << "Gender : " << this->gender << "\n";
        std::cout << "Food Choice : " << this->food_choice << "\n";
    }
};

#endif //RRS_REDESIGN_PERSON_H
