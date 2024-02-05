#include <iostream>
#include <string>

//visibility has nothing to do with performance!

// private, protected, public -> technically visibility is used for code quality
// struct -> public, class-> private

// only exception is "friend" in c++ where it can access private members as well
// public is for all -> inside main method etc....

class Entity {
// private:
//     int X, Y;

protected: // protected means this class along with subclasses can access members
    int X, Y;

    void Print() {}
public:
    Entity() {
        X = 0;
        Print();
    }
};

class Player : public Entity {
public:
    Player() {
        // Print() -> cannot call this since private, but if protected its allowed
    }
};

int main() {

}