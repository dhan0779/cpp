// dynamic arrays! std::vector -> should be called arraylist, can resize
// you can provide the underlying data type it can handle
#include <iostream>
#include <string>
#include <vector>

struct Vertex {
    float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
    stream << vertex.x << ", " << vertex.y << ", " << vertex.z;
    return stream;
}

void Function(const std::vector<Vertex>& vertices);

int main() {
    // Vertex vertices[5];

    std::vector<Vertex> vertices; // can pass any type
    // when should you use vertex pointers rather than vertex objects itself
    // technically more optimal to push objects rather than pointers, memory is contiguous
    // depends also on the size of the mem

    vertices.push_back({1,2,3});
    vertices.push_back({4,5,6});
    for (Vertex& v : vertices) { // avoid copying!!
        std::cout << v << std::endl;
    }

    vertices.erase(vertices.begin()+1); // to remove the second element

    vertices.clear();

}