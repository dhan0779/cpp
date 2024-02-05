// you must either write AND use templates inside an entire cpp file OR
// you must write a template entirely inside of a header file

#include <iostream>
#include <string>

void Print(int value) {
    std::cout << value << std::endl;
}

// notice I have to create an overloaded function just to print another type
void Print(std::string value) {
    std::cout << value << std::endl;
}

// how can we just create a template from this?
// this is a template that will be evaluated at compile time
// template parameter: typename/class, we can call T anything
// template does NOT exist until called, so syntax errors can be common
template<typename T>
void Print(T value) {
    std::cout << value << std::endl;
}

// an entire class
// multiple parameters are possible, size N, type T for the array
template<typename T, int N>
class Array {
private:
    T m_Array[N]; // templates are evaluated at compile time! 
    // so this is created on the stack
public:
     int GetSize() const { return N; }
};

int main() {
    Print(5); // type deduction
    Print("hello"); // if you call with a diff argument, the same function is copied with diff type

    Array<int, 5> array;
    Array<std::string, 50> array2;

}

