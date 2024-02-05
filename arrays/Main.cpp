#include <iostream>
#include <array>

// arrays store data contiguously 

// there also exists std array introduced in C++
// advantages: bounds checking and size

class Entity {
public:
    static const int size = 5; //static to get around size
    // int example[size]; // can't actually do this since it has to be compile time known
    int example[5]; // this would inline the array when looking at Entity
    // int* example = new int[5]; // this would allocate on heap so looking at address of Entity would not show
    // instead it would show the address of the pointer

    // you can't really find size of array doing size()
    // sizeof(a) // sizeof(int) -> 20/4 = 5
    // maintain size by yourself

    std::array<int, 5> another; //  creates array of size 5 of type int

    Entity() {
        for (int i = 0; i < 5; i++) 
            example[i] = 2;
    }
};

int main() {
    int example[5]; // this is an array -> 20 bytes, created on the stack

    int* ptr = example;
    example[0] = 2; 
    example[4] = 4;

    // int a = example[0];
    // example[-1] = 0; // memory access violation

    std::cout << example[0] <<std::endl;
    std::cout << example << std::endl; // prints out memory add since pointer

    for (int i = 0; i < 5; i++)
        example[i] = 2;

    *(ptr+2) = 6; // 2*4 = 8 bytes -> remember ptr is just a number
    // *(int*)((char*)ptr + 8) = 6; // exact same as above
    std::cout << example[2] << std::endl;

    // why allocate heap vs stack? 

    int* another = new int[5]; // created on the heap -> alive until we destroy it

    for (int i = 0; i < 5; i++)
        another[i] = 2;

    delete[] another;
}