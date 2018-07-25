#ifndef RRS_REDESIGN_TRAIN_H
#define RRS_REDESIGN_TRAIN_H

#include <string>



class Train{

protected:
    std::string train_name;
    std::string train_type;
    std::string** constructed_train;
    //string train_route;
    int bogie_count;
    int seat_count_per_bogie;



public:

    Train(std::string train_type_value,int bogie_count_value = 3,int seat_count_per_bogie_value = 2){
        train_type = train_type_value;
        bogie_count= bogie_count_value;
        seat_count_per_bogie = seat_count_per_bogie_value;
    };

    virtual void set_train_name() = 0;

    virtual std::string get_train_name() = 0;

    virtual std::string get_train_type() = 0;

    virtual int get_bogie_count() = 0;

    virtual int get_seat_count_per_bogie() = 0;

    virtual void construct_train() = 0;

    virtual std::string** get_constructed_train() = 0;

    //factory method
    Train* create_train_object(std::string train_type_value);

};


#endif //RRS_REDESIGN_TRAIN_H
