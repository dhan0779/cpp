#include <iostream>
#include <vector>
#include <utility>
#include <string>

// but in general cases, just mke a struct for better organization
struct ShaderProgramSource {
    std::string VertexSource;
    std::string FragmentSource;
};

int main() {
    std::string vs = "hello";
    std::string fs = "hello2";
    // for multiple return types
    // std::tuple<std::string, std::string> sources = std::make_pair(vs, fs);
    std::pair<std::string, std::string> sources = std::make_pair(vs, fs);
    // but how do we obtain it back

    std::string vsOut = std::get<0>(sources);
    std::string fsOut = std::get<1>(sources);
    // OR FOR PAIRS
    std::pair<std::string, std::string> vsfs = std::make_pair(sources.first, sources.second);
    // ShaderProgramSource sps = (sources.VertexSource, sources.FragmentSource); // if it was a struct
    
}