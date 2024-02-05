#include <iostream>
#include <thread>

static bool s_Finished = false;

void DoWork() {
    using namespace std::literals::chrono_literals;

    std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;
    while (!s_Finished) {
        std::cout << "Working...\n";
        std::this_thread::sleep_for(1s);
    }
}

int main() {

    // run a thread
    std::thread worker(DoWork);
    std::cin.get();
    s_Finished = true;
    // wait for exit, block current thread until other thread has completed
    // main thread, starts off a worker thread
    // join waits on the main thread to finish all worker threads
    worker.join();
    
    // this prints out a different thread than above since running on different threads
    std::cout << "Started thread id=" << std::this_thread::get_id() << std::endl;
}