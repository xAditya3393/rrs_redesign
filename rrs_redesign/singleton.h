#ifndef RRS_REDESIGN_SINGLETON_H
#define RRS_REDESIGN_SINGLETON_H

#include <iostream>
#include <iomanip>
#include <ctime>
#include <atomic>
#include <mutex>


//Lazy intialization, Thread Safe - double check locking with atomic type variable
class current_date_time {

private:
    //Private constructor
    current_date_time() {};
    //atomic type enforcing sequencial consistency and inter-thread synchronization
    static std::atomic<current_date_time*> global_time_variable;
    static std::mutex m_; //lock variable

public:
    // responsible for creating a single instance of the class
    static current_date_time* create_instance();

    void time_output(){
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        std::cout << std::put_time(&tm, "%c %Z") << "\n";
    }

};





#endif //RRS_REDESIGN_SINGLETON_H
