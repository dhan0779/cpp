#include <iostream>
#include <string>

// pass in a const ref
void PrintString(const std::string& string) { // don't put std::string string inside as a param -> actually a copy 
    // string += 'h'; -> typically do not want to modify
    std::cout << string << std::endl;
}

int main() {
    // const char* name = "Cherno"; // strings are immutable - fixed allocated block of memory -> const
    std::string name = "Cherno" + std::string("hello!"); // + " hello!"; -> not allowed

    using namespace std::string_literals;
    std::string nme = "Cherno"s + "hello"; //C++14 -> string literal s
    // null termination character
    bool contains = name.find("no") != std::string::npos; // flag to see if it contains a string
    name += "hello!";

    // strings are stored in a read only section of memory -> store as char name[] instead of char* name
    char name2[7] = { 'C', 'h', 'e', 'r', 'n', 'o', 0 };

    std::cout << name2 << std::endl;

    std::cout << name << std::endl;
    // name[2] = 'a'; // const so no change

    const wchar_t* name3 = L"Cherno"; // wide character
    const char16_t* name4 = u"Cherno"; // 16 bits for char
    const char32_t* name5 = U"Cherno"; //32 bits for char

    const char* example = R"(Line 1
    Line2
    Line3
    Line4)"; // ignore escape -> used for multiple lines
}