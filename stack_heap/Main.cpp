#include <iostream>
#include <string>

struct Vector3 {
    float x, y, z;
};

int main() {
    int value = 5; // allocated on the stack
    int* hvalue = new int; // heap
    *hvalue = 5;

    int array[5]; // stack
    int* harray = new int[5]; // heap

    Vector3 vector; // stack
    Vector3* hvector = new Vector3(); // heap

    // stack pointer just moves along so all these are basically contiguous for
    // stack allocated, this is why its extremely fast

    // for heap, its all in different places
    delete hvalue;
    delete[] harray; // have to delete if not using smart pointers
}