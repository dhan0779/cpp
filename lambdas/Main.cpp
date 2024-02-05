#include <iostream>
#include <algorithm>

// void ForEach(const std::vector<int>& values, void(*func)(int)){
//     for (int value : values) {
//         func(value);
//     }
// }

// function pointer in a clas
void ForEach(const std::vector<int>& values, const std::function<void(int)>& func) {
    for (int value : values) {
        func(value);
    }
}

int main() {
    // what are lambdas used for?
    // whenever you have a function pointer, you can just use a lambda
    // anonymous function
    std::vector<int> values = {1,5,4,2,3};

    int a = 5;
    // how do we print a inside the lambda below? can pass by value or reference -> for the capture group
    // how do we want to pass the variable in? = -> value, & -> reference

    // square bracket -> capture list -> a comma separated list of 0 or more captures
    // need mutable if you want to change a variable inside the lambda
    auto lambda = [=](int value) mutable { a = 4; std::cout << "Value: " << value << std::endl; };
    ForEach(values, lambda);

    // returns an iterator for the first element that matches the expression
    auto it = std::find_if (values.begin(), values.end(), [](int value){ return value > 3; });
    std::cout << *it << std::endl;
}