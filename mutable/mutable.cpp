#include <iostream>
#include <string>

class Entity {
private:
    std::string m_Name;
    mutable int m_DebugCount = 0; // allows in const method
public:
    Entity() : m_Name("Unknown") {  // member intializer lists, functional difference for performance
        // removes clutter for the actual constructor
    }
    const std::string& GetName() const { 
        m_DebugCount++;
        return m_Name;
    }
};

int main() {
    int x = 8;
    auto f = [=]() mutable { // use mutable keyword
        // how do we use x?
        x++;
        std::cout << "Hello" << std::endl;
    };

    f();
}