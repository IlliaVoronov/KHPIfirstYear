#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int shared_var = 0; 

void increment() {
    for (int i = 0; i < 1000000; i++) {
        mtx.lock(); 
        shared_var++;
        mtx.unlock();
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << "Shared variable value (with mutex): " << shared_var << std::endl;
    
    // Without mutex
    std::thread t3(increment);
    std::thread t4(increment);
    t3.join();
    t4.join();
    std::cout << "Shared variable value (without mutex): " << shared_var << std::endl;
    
    return 0;
}

