#include <iostream>
#include <string>

class Entity {
private: 
    std::string m_Name;
    int m_Age;

public:
    Entity(const std::string& name) : m_Name(name), m_Age(-1) {}
    explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {} //explicitly called -> math libraries.5f
};

void PrintEntity(const Entity& entity) {}

int main() {
    // Entity a("Ch");
    // Entity b(22); // these are pretty standard ways of constructing

    // Entity a = 22; // this is still legal -> implicit conversion, takes in an integer and name
    // 22 can be converted into an Entity since there exists a constructor for it
    // PrintEntity(22);
    // PrintEntity("Ch"); // this doesn't work only allowed to do 1 implicit conversion
    // char array -> string -> Entity
    PrintEntity(std::string("Ch"));
    PrintEntity(Entity("Ch"));

    // What is explicit? basically nullifies the implcit conversion
    Entity b(22);
    Entity b = Entity(22);


}