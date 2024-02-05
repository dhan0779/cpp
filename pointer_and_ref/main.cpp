#include <iostream> //search folder c standardlibrary vs c++ (doesn't use .h)
#include "Log.h" // relative to current file 

#define LOG(x) std::cout << x << std::endl;

int Multiply(int a, int b) { // void return type means nothing, param not necessary
    return a*b;
}

void MultiplyAndLog(int a, int b) {
    int result = Multiply(a,b);
    std::cout << result << std::endl;
}

void IncrementByValue(int value) { // pass by value doesn't actually change the value of a
    value++;
}

void IncrementByPtr(int* value) {
    (*value)++; // deref since we passed in a pointer or mem address
}

void IncrementByRef(int& value) { //takes in a reference which 
    value++;
}

// ONLY DIFFERENCE BETWEEN STRUCT AND CLASS -> STRUCT: PUBLIC, CLASS: PRIVATE
// the only reason structs exist is that it wants to maintain backward compat with C
// use classes with inheritance

class Player { // classes allow you to group variables into a type
public:
    int x,y; // only functions inside class can modify these -> default private
    int speed;

    void Move(int xa, int ya) {  // this is okay but should put methods inside the class
        x += xa * speed;
        y += ya * speed;
    }
}; //need semicolon here

// void Move(Player& player, int xa, int ya) {  // this is okay but should put methods inside the class
//     player.x += xa * player.speed;
//     player.y += ya * player.speed;
// }

struct Vec2 {
    float x, y;
    void Add(const Vec2& other) {
        x += other.x;
        y += other.y;
    }
};

// these aren't grouped at all if needed -> define a type thats only one of these 3?
// int A = 0;
// int B = 1;
// int C = 2;

enum Example : unsigned char { // can define a type
    A, B, C // if you don't specify a value, default 0,1,2... incrementing or if A = 5 ...
};

int main() { // unique of return value -> automatically assumes return 0
    Example value = A;
    Player player;
    player.Move(1, -1);
    InitLog();
    unsigned int variable = 8; //32 bits instead of 31 when unsigned

    char aaaaa = 'A'; //1 byte but prints out as the char not the number
    short b = 'B';
    float dec = 5.5f; // need this f to denote float instead of double -> 4 bytes 
    double decd = 5.2; // 8 bytes

    std::cout << aaaaa << std::endl;
    variable = 20;
    std::cout << variable << std::endl;

    int result = Multiply(3,2);
    std::cout << result << std::endl;

    MultiplyAndLog(90,45);

    int x = 5;
    bool comparisonResult = x == 5;
    if (comparisonResult) {
        Log("Hello World!");        
    }
    // const char* ptr = nullptr; //nullptr
    // if (ptr)
    //     Log(ptr); // if one line, you can skip brackets
    // // else if (ptr == "Hello")
    // //     Log("Ptr is hello");
    // else
    //     Log("Ptr is null");

    int i = 0;
    for (int i = 0; i < 5; ) { // condition in the middle and statement after loop <- this is valid!
        Log("Hello World!");
        i++;
    }
    while (i < 5) {
        Log("while loop!");
        i++;
    }

    i = 0;
    do {
        Log("do while loops happen at least once!"); //as opposed to just regular while loops
        i++;
    } while (i < 5);

    // A POINTER IS JUST A NUMBER THAT STORES A MEMORY ADDRESS
    int var = 8; // creates var on the stack
    // void* ptr = nullptr; // memory address <- 0 is not a valid address 

    // why can't we store &var in an integer?  sizes might not match, type safety
    // we can also change the type from void to int! doesn't change anything at all since no "type"

    // if a pointer is incremented (ptr++), then the address it holds is not always incremented by 1 byte
    // instead it increases by the size of its type 0x00..4 -> 0x00..8 for integers etc...

    int* ptr = &var; // where is var in memory, what is your  memory address? using & 
    // now how do I get access to var from ptr? dereference
    *ptr = 10;
    LOG(var);

    char* buffer = new char[8]; // allocates 8 bytes of memory and returns a pointer to the beginning of mem
    memset(buffer, 0, 8); // memset fills in memory:  memset(pointer, value, how many bytes)

    char** ptrb = &buffer; // double pointer -> just a pointer to another pointer address

    delete[] buffer; // explicity delete from heap

    //REFERENCES
    // a reference has to reference an already existing variable -> they aren't new variables
    // refs only exist in source code <- there's still only one variable a
    // once you declare a reference, you cannot change what it references 

    // int& ref = a;
    // int b = 8;
    // ref = b; <- this will actually just change a to b or 8

    int a = 5;
    int& ref = a; // ampersand is actually part of the type! we call this an alias
    ref = 2;
    LOG(a); // a will be 2 now since ref is a
    IncrementByRef(a); // we pass in a but we'll actually change the var a by reference
    LOG(a);

    
}