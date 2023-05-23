//Works on Linux
// Compile with: g++ server.cpp -o server

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

const char *fifo_path = "/tmp/my_fifo";

int main() {
    mkfifo(fifo_path, 0666);

    int fd = open(fifo_path, O_RDONLY);
    int L, U;
    read(fd, &L, sizeof(L));
    read(fd, &U, sizeof(U));
    close(fd);

    long long sum = 0;
    long long product = 1;
    for (int i = L; i <= U; i++) {
        sum += i;
        product *= i;
    }

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    unlink(fifo_path);

    return 0;
}
