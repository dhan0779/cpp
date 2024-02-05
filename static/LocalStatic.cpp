#include <iostream>

class Singleton {
public:
    static Singleton& Get(){
        static Singleton instance;
        return instance;
    }

    void Hello() {}
};


void Function() {
    // but is different from global since its within the scope of the function
    static int i = 0; // basically does not set to 0 when function keeps getting called
    i++;
    std::cout << i << std::endl;
}

int main() {
    Function();
    Function();
    Function();
    Singleton::Get().Hello();