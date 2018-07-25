#include "singleton.h"

/*
 *
 * Lazy Initiation - Thread Unsafe
 *
 *
class current_date_time {

private:
 //private constructor and destructor
    current_date_time() {};
    ~current_date_time(){};

public:
    static void create_instance(); //creates instance by invoking the private constructor
    static void delete_instance(); //deallocates the heap memory
    static current_date_time* global_time_variable; //globally accessable variable

    void time_output(){
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        std::cout << std::put_time(&tm, "%c %Z") << "\n";
    }

};


current_date_time* current_date_time::global_time_variable = NULL;

//lazy initialization
void current_date_time::create_instance() {
    if(current_date_time::global_time_variable == NULL)
        global_time_variable =  new current_date_time();
}


void current_date_time::delete_instance() {
    delete global_time_variable;
    global_time_variable = NULL;
}
*/

/*--------------------------------------------------------------------------------------------------------------------*/



//atomic type ensures single time object construction
std::atomic<current_date_time*> current_date_time::global_time_variable {nullptr};
std::mutex current_date_time::m_;

current_date_time* current_date_time::create_instance(){
    if(global_time_variable == nullptr){
        std::lock_guard<std::mutex> lock(m_); // lock_guard ensures lock release under exceptions, releases after scope ends
        if(global_time_variable == nullptr){
            global_time_variable = new current_date_time();
        }
    }
    else{
        std::cout << "already created!!"<<"\n";
    }

    return global_time_variable;
}


/*
int main() {

    current_date_time* thread_safe_variable = current_date_time::create_instance();
    current_date_time* thread_safe_variable_2 = current_date_time::create_instance();
    return 0;
}
 */



/*--------------------------------------------------------------------------------------------------------------------*/

/*
 *
 * Eager-Initialization, Thread Safe - double check locking with atomic type
 *
 *
class current_date_time {

    //typedef std::shared_ptr<std::atomic<current_date_time*>> smart_pointer; in case of smart pointer usage

private:
 //private constuctor and lock variable
    current_date_time() {};
    static std::mutex m_;

public:
    //creates global instance on call - saves memory if instance is memory intense
    static std::atomic<current_date_time*>& create_instance();
    //responsible for assignment of single class object with lock variable
    static current_date_time*& initialize_instance(current_date_time*& global_time_variable);

    void time_output(){
        std::time_t t = std::time(nullptr);
        std::tm tm = *std::localtime(&t);
        std::cout << std::put_time(&tm, "%c %Z") << "\n";
    }

};


std::mutex current_date_time::m_;

std::atomic<current_date_time*>& current_date_time::create_instance(){
    static std::atomic<current_date_time*> global_time_variable = nullptr; //global variable creation
    return global_time_variable;
}



current_date_time*& current_date_time::initialize_instance(current_date_time*& global_time_variable){

    if(global_time_variable == nullptr){  //check to see if the variable is empty
        std::lock_guard<std::mutex> lock(m_);  //acquire lock
        if(global_time_variable == nullptr){  //second check if multiple threads acquire lock
            global_time_variable = new current_date_time(); //only one thread executes this line atomically
        }
    }

    return global_time_variable;
}



int main() {

    current_date_time* eager_initialized_variable = current_date_time::create_instance();
    current_date_time* after_thread_safe_variable = current_date_time::initialize_instance(eager_initialized_variable);
    after_thread_safe_variable->time_output();

    return 0;
}
 */

