// smart pointers are a way to automate the process of allocating and freeing memory
// don't have to call new/delete

// unique_ptr -> when the pointer goes out of scope, it will be deleted
// can't copy a unique pointer, suppose you have have two unique pointers that point to the same loc
// if you free the memory from one pointer, the other points to nothing

#include <iostream>
#include <string>
#include <memory> // needed for the smart_ptr

class Entity {
public:
    Entity() {
        std::cout << "Created Entity!" << std::endl;
    }
    ~Entity() {
        std::cout << "Destroyed Entity!" << std::endl;
    }
};

int main() {
    {
        std::shared_ptr<Entity> e0;
        {
            // std::unique_ptr<Entity> entity(new Entity());
            std::unique_ptr<Entity> entity = std::make_unique<Entity>(); // do this for exception safety
            // std::unique_ptr<Entity> e0 = entity; // can't actually do this

            // how to share the pointer, like pass it to a function?
            // shared pointer -> reference counting, when it reaches 0 -> free memory
            std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>();
            // std::shared_ptr<Entity> sharedEntity(new Entity()); // don't do this
            // why? shared_ptr has to to allocate another block of memory for the reference count -> control block
            // construct together for efficiency -> gets rid of new keyword too!
            e0 = sharedEntity; // EXPLICIT COPYING

            std::weak_ptr<Entity> weakEntity = sharedEntity; // won't increase reference count 
            // thus it won't use ref count
        }
        // when the first scope dies, the shared entity still exists -> has to wait until all scopes die
    }
}