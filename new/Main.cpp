// use new to allocate memory on the heap
// needs to find a place in the heap where there are four bytes of contiguous memory -> pointer
// maintains a freelist

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
    int a = 2;
    int* b = new int[50]; // allocate on the heap

    // Whats the difference between the two below? 
    // The first actually allocates the memory as well as calls the default constructor
    // The second ONLY allocates the memory
    Entity* e = new Entity(); 
    // Entity* e = new(b) Entity(); // placement new
    // Entity* e = (Entity*) malloc(sizeof(Entity)); // don't do this yet

    // must use delete after the new
    // calls free()
    // delete[] e;
    delete e;
}