#include <iostream>

class Entity {
public:
    float X, Y;

    void Move(float xa, float ya) {
        X+=xa;
        Y+=ya;
    }
};

class Player : public Entity { // inheritance -> has type Entity and Player
public:
    const char* Name;

    void PrintName() {
        std::cout << Name << std::endl;
    }
};

int main() {
    std::cout << sizeof(Entity) << std::endl; // size of float X, Y
    std::cout << sizeof(Player) << std::endl; // size of Entity and Name (4 bytes)
    Player player;
    player.Move(5, 5);
    player.PrintName();
}