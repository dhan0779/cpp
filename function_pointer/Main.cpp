#include <iostream>
#include <vector>

void HelloWorld(int a) {
    std::cout << "Hello World! Value: " << a << std::endl;
}
void PrintValue(int value) {
    std::cout << "Value: " << value << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int)) {
    for (int value : values) {
        func(value);
    }
}

// function is CPU instructions
int main() {
    // function name, int as parameter
    typedef void(*HelloWorldFunction)(int); // complicated so its easier to typedef it

    // void(*function)(); this is the type, function is a name
    auto function = HelloWorld;
    function(2); // calls function

    HelloWorldFunction function = HelloWorld;
    function(8);

    // but why would you use function pointers?
    std::vector<int> values = {1,5,4,2,3};
    ForEach(values, PrintValue);

    // for each of the values, its actually going to call the PrintValue function
    // basically a higher order function

    // or we can use a lambda -> capture
    ForEach(values, [](int value) { std::cout << "Value: " << value << std::endl; });

}