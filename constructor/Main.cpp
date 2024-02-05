#include <iostream>

class Entity {
public:
    float X, Y;

    // there actually exists a default constructor, doesn't really do anything
    // Entity () {}

    // constructor! 
    Entity() {
        std::cout << "Constructed Entity!" << std::endl;
        X = 0.0f;
        Y = 0.0f;
    }

    Entity(float x, float y) {
        X = x;
        Y = y;
    }

    // void Init() {
    //     X = 0.0f;
    //     Y = 0.0f;
    // }

    ~Entity() { //destructor - has a tilde
        std::cout << "Destroyed Entity!" << std::endl;
    }

    void Print() {
        std::cout << X << ", " << Y << std::endl;
    }
};

// suppose we have a class with only static methods
// want to avoid people from instantiating an actual Log object like Log l
// make the constructor private!
class Log {
private:
    Log() {}
public:
    // OR instead of making the default constructor private: 
    // Log() = delete;
    static void Write() {

    }
};

int main() {
    Log::Write();
    // Entity e;
    // constructors only run when you instantiate an object
    Entity f;
    Entity e(10.0f, 5.0f);
    // e.Init(); // but this means every time we make an entity, we need to call Init
    e.Print();
};