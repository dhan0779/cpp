#include <iostream>
#include <string>

class Entity {
public:
    void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr {
private:
    Entity* m_Obj;
public:
    ScopedPtr(Entity* entity) : m_Obj(entity) {}

    ~ScopedPtr() {
        delete m_Obj;
    }

    Entity* operator->() {
        return m_Obj;
    }
};

struct Vector3 {
    float x, y, z;
};

int main() {
    Entity e;
    e.Print();

    Entity* ptr = &e;
    (*ptr).Print(); // okay but clunky
    ptr->Print(); // shortcut for manually dereferencing
    //you can overload arrow operator!

    ScopedPtr entity = new Entity();
    entity->Print();

    int offset = (int)&((Vector3*)nullptr)->x; // gets the offset of x, y, z in mem
    // nice for serializing data
}