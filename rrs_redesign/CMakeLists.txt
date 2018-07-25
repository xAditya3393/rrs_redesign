cmake_minimum_required(VERSION 3.10)
project(rrs_redesign)

set(CMAKE_CXX_STANDARD 17)

add_executable(rrs_redesign main.cpp singleton.cpp singleton.h station.h station.cpp Train.h Train.cpp Normal_Train.h costs.h Normal_Train.cpp Express_Train.h Express_Train.cpp person.h file_operations.h file_operations.cpp functionality.h functionality.cpp reservation_interface.h person_originator.h person_caretaker.h person_caretaker.cpp person_originator.cpp reservation_interface.cpp)