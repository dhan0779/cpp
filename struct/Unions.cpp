#include <iostream>

enum Type {str, num};

struct Entry {
    char* name;
    Type t;
    char* s; // use s if t == str
    int i; // use i if t == int
};

// basically doing this is a waste of space since we can only use s or i at the same time
// so we can make the following union: a struct in which all members are allocated at the same address so that
// union occupies only as much space as its largest member
// A union can hold a value for only one member at a time

union Value {
    char*s;
    int i;
};

// a union cannot have virtual functions, cannot have members of the reference type
// cannot have a base class cannot be used as a base class

struct Entry2 {
    char* name;
    Type t;
    char* s; // use s if t == str
    int i; // use i if t == int
    Value v;
};

void f(Entry* p) {
    if (p->t == str) {
        std::cout << p->s;
    }
}

int main() {

}