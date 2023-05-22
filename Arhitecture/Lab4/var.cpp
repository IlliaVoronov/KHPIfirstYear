#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int shared_var = 0;
bool ready = false;

void increment() {
    for (int i = 0; i < 1000000; i++) {
        std::unique_lock<std::mutex> lock(mtx);
        shared_var++;
        if (shared_var == 1000000 && !ready) {
            ready = true;
            cv.notify_all();
        }
    }
}

int main() {
    // With conditional variable
    std::thread t1(increment);
    std::thread t2(increment);
    {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return ready; });
    }
    t1.join();
    t2.join();
    std::cout << "Shared variable value (with conditional variable): " << shared_var << std::endl;

    // Without conditional variable
    shared_var = 0;
    ready = false;
    std::thread t3(increment);
    std::thread t4(increment);
    t3.join();
    t4.join();
    std::cout << "Shared variable value (without conditional variable): " << shared_var << std::endl;

    return 0;
}

