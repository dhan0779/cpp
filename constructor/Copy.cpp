#include <iostream>
#include <string>

struct Vector2 {
    float x, y;
};

// creating a string class
class String {
private:
    char* m_Buffer; // for the chars
    unsigned int m_Size; // keeps track of the size of the string
public:
    String(const char* string) {
        m_Size = strlen(string);
        m_Buffer = new char[m_Size+1]; // for the null termination character or strcpy
        memcpy(m_Buffer, string, m_Size); // dest, src, size
        m_Buffer[m_Size] = 0;
    }

    friend std::ostream& operator<<(std::ostream& stream, const String& string);

    char& operator[](unsigned int index) {
        return m_Buffer[index];
    }

    // DEEPY COPY
    String(const String& other) : m_Size(other.m_Size) { // copy constructor // = delete; to avoid copying
        m_Buffer = new char[m_Size+1];
        memcpy(m_Buffer, other.m_Buffer, m_Size+1); 
    }

    ~String() { // since we don't have a smart pointer
        delete[] m_Buffer;
    }
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
    stream << string.m_Buffer; // able to access this private member since the function is labelled as a friend
    return stream;
}

void PrintString(const String& string) { // mark it as const so it can't be modified -> reference to avoid copying
    std::cout << string << std::endl;
}

int main() {
    // basically, a rule of thumb is that the = sign will copy the values
    // int a = 2;
    // int b = a; two different references since b is a copy of the values

    Vector2* a = new Vector2();
    Vector2* b = a; // copying the pointer, two pointers to the access in memory
    b->x = 2; //

    String string = "CH";
    String second = string; // need to implement the copy constructor, or else the memory of the buffer is the same
    // basically m_Buffer is the same to the same point in memory

    second[2] = 'a';

    std::cout << string << std::endl;
    std::cout << second << std::endl;
}