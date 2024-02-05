#include <iostream>
#include <string>

// NEVER EVER USE A NAMESPACE IN A HEADER FILE !!!

namespace apple {
    // implicit conversion
    void print(const std::string& text) {
        std::cout << text << std::endl;
    }
}

namespace orange { 
    void print(const char* text) {
        std::string temp = text;
        std::reverse(temp.begin(), temp.end());
        std::cout << temp << std::endl;
    }
}

using namespace apple;
using namespace orange;

int main() {
    // which one gets called if we're using both namespaces
    // orange! because it is a const char*, no conversion takes precendence
    // still super confusing

    // if they were both char* then it would be an error due to duplicate symbol
    // C doesn't have namespaces, so it was usually like orange_print() or apple_print(), prepending lib
    // primary purpose of namespaces is to avoid naming conflicts
    // :: this is a scope resolution operator

    namespace a = apple;
    // aliases for namespaces, useful for nested namespaces
    print("hello");
}