#include <iostream>

// global or static?
static int s_Variable; // one way to use the s_Variable define in Static.cpp is to use extern keyword

// TECHNICALLY this could be global, so why? because it makes sense for x,y to be in entity -> organized
struct Entity {
    static int x, y; // static in the context of structs/classes -> all instances have one member

    void Print() { // if static, cannot use nonstatic x,y
        std::cout << x << ", " << y << std::endl;
    }
};

// need to define the static variables
// shared memory for static
int Entity::x;
int Entity::y;

int main() {
    Entity e;
    e.x = 2; // do this if NOT static
    e.y = 3;

    // Entity e1 = { 5, 8 }; -> not valid with static
    Entity::x = 5; // do this when STATIC
    Entity::y = 8;
    e.Print();
    // Entity::Print(); -> if static
    // e1.Print();
    // std::cout << s_Variable << std::endl;
}