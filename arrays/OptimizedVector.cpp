#include <iostream>
#include <string>
#include <vector>

// optimizing is all about knowing our environment

struct Vertex {
    float x, y, z;

    Vertex(float x, float y, float z) : x(x), y(y), z(z) {}

    Vertex(const Vertex& vertex) : x(vertex.x), y(vertex.y), z(vertex.z) {
        std::cout << "Copied!" << std::endl;
    }
};

int main() {
    std::vector<Vertex> vertices; // if we did vertices(3) it would construct 3 vertex objects
    vertices.reserve(3); // reserves enough memory

    vertices.push_back(Vertex(1,2,3));
    vertices.push_back(Vertex(4,5,6)); // 3 copies!
    // constructs/copies vertex on the stack in main, then from main into the actual vector in memory
    // vector is being resized constantly!
    vertices.push_back(Vertex(7,8,9)); // 6 copies

    vertices.emplace_back(1,2,3); //tells to construct a vector in place with the following values
    // not a single copy!
}