#ifndef RRS_REDESIGN_COSTS_H
#define RRS_REDESIGN_COSTS_H

template <typename T = std::string>
class costs{

public:
    virtual T ticket_cost() = 0;
    virtual T cancellation_cost() = 0;
    virtual T food_cost() = 0;
};

#endif //RRS_REDESIGN_COSTS_H
