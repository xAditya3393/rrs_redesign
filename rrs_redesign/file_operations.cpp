
#include <iostream>
#include <fstream>
#include <vector>
#include "file_operations.h"
#include "singleton.h"


void file_operations::delete_file_contents(){
    std::ofstream ofs(file_path, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}

std::vector<std::string> file_operations::get_parsed_string(std::string s){

    std::vector<std::string> result;
    std::string delimiter =",";

    size_t delimiter_position = 0;
    std::string token;
    while ((delimiter_position = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, delimiter_position);
        result.push_back(token);
        s.erase(0, delimiter_position + delimiter.length());
    }
    result.push_back(s);

    return result;
}



std::string file_operations::get_file_path(){
    return file_path;
}


void file_operations::take_user_file_path() {

    std::string _file_path;

    std::cout << "Enter Full File path to read your information : \n";
    std::getline(std::cin,_file_path);
    file_path = _file_path;

}

std::string file_operations::file_input_for_details() {

    std::string _name, _age, _gender, _food_choice;
    std::ifstream istream(file_path);

    //istream.open(file_path);

    getline(istream,_name);
    getline(istream,_age);
    getline(istream,_gender);
    getline(istream,_food_choice);

    istream.close();

    std::string full_details = _name+","+_age+","+ _gender+","+_food_choice;

    return full_details;

}



void  file_operations::file_output_for_ticket(person_originator* details){


    current_date_time* ticket_time = current_date_time::create_instance();

    std::ofstream ostream(file_path,std::ios::app);
    //ostream.open(file_path,std::ios::app);

    ostream << details->get_current_name() << std::endl;
    ostream << details->get_current_age() << std::endl;
    ostream << details->get_current_gender() << std::endl;
    ostream << details->get_current_food_choice() << std::endl;

    std::cout << "Ticket Printed  at : ";
    ticket_time->time_output();
    std::cout << std::endl;

    ostream.close();

}

void file_operations::reading_ticket_for_confirmation(){

    std::string confirm_details = file_input_for_details();
    std::vector<std::string> details = get_parsed_string(confirm_details);

    std::cout << "Your Details : \n";
    std::cout <<"Name :" << details[0] << "\n";
    std::cout <<"Age :" << details[1] << "\n";
    std::cout <<"Gender :" << details[2] << "\n";
    std::cout <<"Food_Choice :" << details[3] << "\n";

}