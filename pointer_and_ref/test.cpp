#include <iostream>
#include <string>

class Entity {
private:
    int m_X, m_Y;
    mutable int var; // allows you to change var inside const methods
public:
    // imagine const int* const GetX() const {} // cannot modify pointer, content, and class member
    int GetX() const { // after a method name in a class, you cannot modify a class member
        // m_X = 2;  // not possible
        var = 2;
        return m_X;
    }

    void SetX(int x) {
        m_X = x;
    }
};

int main() {
    const int MAX_AGE = 90; // declare a variable and will not modify it
    
    const int* a = new int; // means you cannot change the content of the pointer
    // *a = 2;

    int* const a = new int; // can change the content of the pointer but can't reassign to point to something else
    
    a = (int*)&MAX_AGE;

    // pointer itself or the contents of what its pointing to
    std::cout << *a << std::endl;

}