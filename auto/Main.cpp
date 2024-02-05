#include <iostream>
#include <string>
#include <vector>
#include <unordered_map> 

std::string GetName() {
    return "Ch";
}

class Device {};

class DeviceManager {
private:
    std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
    const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() {
        return m_Devices;
    }
};

// auto tradeoff vs readability 
// basically if type is reallyyyy long -> types are too complicated (but should avoid this)

int main() {
    int a = 5;
    auto b = a; // int b 
    // c++ is still considered strongly typed programming language

    auto name = GetName(); // will be deduced to std::string or whatever the return type is

    std::vector<std::string> strings;
    strings.push_back("Apple");
    strings.push_back("Orange");

    // iterator is a concept, not a concrete type
    // they can generally be incremented and they can be accessed or dereferenced
    // essentially abstractions of a pointer
    for (std::vector<std::string>::iterator it = strings.begin(); it != strings.end(); it++) {
        std::cout << *it << std::endl;
    }
    // OR it could be cleaner to write with auto
    for (auto it = strings.begin(); it != strings.end(); it++) {
        std::cout << *it << std::endl;
    }

    using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;
    // using and typedef are almost identical -> typedef introduced in C++11
    // The alias declaration is compatible with templates, whereas the C style typedef is not

    DeviceManager dm;
    const DeviceMap& devices2 = dm.GetDevices();

    // still need to reference to avoid copying
    const auto& devices = dm.GetDevices();
}