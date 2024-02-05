#include <iostream>
#include <string>

using String = std::string;

class Entity {
private:
    String m_Name;
public:
    Entity() : m_Name("Unknown") {}
    Entity(const String& name) : m_Name(name) {}

    const String& GetName() const { return m_Name; }
};

int main() {
    Entity* e;
    {
        Entity entity("CH"); // uses default constructor
        // basically always instantiate an object like this when you can -> fastest
        // Why can't you instantiate  like this then? want to outlive the lifecycle of this function
        // OR stack space might be too small
        e = &entity;
    }
    Entity* entity = new Entity("C"); // returns location on the heap where this pointer is
    std::cout << entity->GetName() << std::endl; // arrow operator for heap allocated
    // have to free that memory
    delete entity; // if you use new, use delete keyword
}