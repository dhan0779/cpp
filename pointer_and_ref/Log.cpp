#include "Log.h" 
#include <iostream>
// void Log(const char* message); // declaration of a function -> move to header file to avoid duplication!

void Log(const char* message) { //function signature
    std::cout << message <<std::endl; 
}

void InitLog() {
    Log("Initializing Log!"); // how do we know this exists?
}