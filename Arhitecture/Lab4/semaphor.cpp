#include <iostream>
#include <thread>
#include <semaphore.h>

sem_t sem;
int shared_var = 0;

void increment() {
    for (int i = 0; i < 1000000; i++) {
        sem_wait(&sem); 
        shared_var++; 
        sem_post(&sem); // signal semaphore
    }
}

int main() {
    sem_init(&sem, 0, 1); 
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << "Shared variable value (with semaphore): " << shared_var << std::endl;
    
    // Without semaphore
    std::thread t3(increment);
    std::thread t4(increment);
    t3.join();
    t4.join();
    std::cout << "Shared variable value (without semaphore): " << shared_var << std::endl;
    
    sem_destroy(&sem); // destroy semaphore
    return 0;
}

