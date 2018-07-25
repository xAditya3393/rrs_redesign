#include "Train.h"
#include "Normal_Train.h"
#include "Express_Train.h"

Train* Train::create_train_object(std::string train_type_value) {
    if(train_type_value == "NT")
        return new Normal_Train();
    else if(train_type_value == "ET")
        return new Express_Train();

    return nullptr;
}