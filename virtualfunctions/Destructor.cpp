#include <iostream>

// a destructor can be declared virtual and should be used with a class with a virtual function
class Shape {
public:
    virtual void draw() = 0; // pure virtual function since "= 0" denotes purity
    virtual ~Shape();
};

class Circle {
public: 
    void draw();
    ~Circle(); // overrides ~Shape()
};

void user(Shape* p) {
    p->draw();
    delete p; // invokes the appropriate destructor
}

int main() {
    
}