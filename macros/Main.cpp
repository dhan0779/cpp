// replace text in our code with something else F&R
#include <iostream>
#include <string>

// but you shouldn't do this! why would you?
// imagine this was defined in a different file :/
#define WAIT std::cin.get() // anytime youencounter this symbol, replace it

// also silly, but also just another example
#define OPEN_CURLY {

#define LOG(x) std::cout << x << std::endl

int main() OPEN_CURLY
    LOG("Hello");
    WAIT;
}


// I think it would also be helpful to show common pitfalls of parameterized macros, such as the following 2 examples:
// ===================
#define MAX(x, y) x > y ? x : y
int main() { return MAX(7,5) * 10; }
// Here main() will return 7 instead of 70:
// 7 > 5 ? 7 : 5 * 10  ==>  7
// To fix this, do:
#define MAX(x, y) (x > y ? x : y)
// ===================
// Another issue can be seen in this example:
#define MULT(x, y) (x * y)
int main() { return MULT(2+5, 10); }
// Here main() will return 52 instead of 70:
// 2+5*10  ==> 52
// To fix this, do:
#define MULT(x,y) ((x) * (y))
// Of course, y can be a pointer so it is possible that *(y) is seen as a dereference. In addition, either x or y can be almost any text which can result in weird generated code.
