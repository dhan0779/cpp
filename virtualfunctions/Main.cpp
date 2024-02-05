#include <iostream>
#include <string>

class Printable {
public:
    virtual std::string GetClassName() = 0;
}; 

// when a virtual function is overridden, the most-derived version is used at all levels
// a pure virtual function is a virtual function that is required to be implemented by a derived class
// if the derived class is not abstract

class Entity : public Printable {
public: 
    virtual std::string GetName() { return "Entity"; }  // virtual! generate a vtable for this function
    // virtual std::string GetName() = 0; // 0 denotes pure virtual function
    std::string GetClassName() override { return "Entity"; }
};

class Player : public Entity { // ,Printable if Entity didn't extend Printable
private:
    std::string m_Name;
public:
    Player(const std::string& name) // constructor
        :m_Name(name) {}

    std::string GetName() override { return m_Name; } //override keyword introduce C++11 -> readability
    std::string GetClassName() override { return "Player"; }
};

void PrintName(Entity* entity) {
    std::cout << entity->GetName() << std::endl;
}

class A : public Printable {
    std::string GetClassName() override { return "A"; }
};

void Print(Printable* obj) {
    std::cout << obj->GetClassName() << std::endl;
}

// RUNTIME COSTS WITH VIRTUAL FUNCTIONS:
// additional memory required to store in the vtable
// every time we call a virtual function, we have to go to the table to see which function was mapped

// virtual functions introduce dynamic dispatch, implemented by the vtable
// vtable contains all the mapping of virtual functions for runtime

// to overwrite a function, you have to mark the base function as virtual in the base class


// https://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself
int main() {
    Entity* e = new Entity();
    // std::cout << e->GetName() << std::endl;
    // PrintName(e);

    Player* p = new Player("Cherno");
    // std::cout << p->GetName() << std::endl;
    // PrintName(p);

    Print(e);
    Print(p);
    // Print(new A());

    Entity* entity = p;
}