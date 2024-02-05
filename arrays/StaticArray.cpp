// arrays that do not grow, same type
#include <iostream>
#include <array>



void PrintArray(int* array, unsigned int size) { // have to explicity put size as an argument
    for (int i = 0; i < size;) {}
}

void PrintArray(const std::array<int, 5>& data) { // how can we get this size? 
    for (int i = 0; i < data.size();) {}
}
// we have to maintain the size of the array in the regular c-style
// both are stored on the stack, but bounds checking on std::array

// the size of an array isn't stored -> it's part of the type and known at compile time


int main() {
    std::array<int, 5> data;
    data[0] = 2;
    data[4] = 1;

    // whats the different between standard C style arrays vs the standard lib array
    // use for performance benefits
}