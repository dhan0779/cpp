#include <iostream>
#include <string>

class Entity {
public:
    int x, y;

    Entity(int x, int y) {
        // this is an Entity* const // not allowed to reassign this
        this->x = x;
        (*this).y = y;

        PrintEntity(this);
    }

    int GetX() const {

    }
};


void PrintEntity(Entity* e) {

}

int main() {

}