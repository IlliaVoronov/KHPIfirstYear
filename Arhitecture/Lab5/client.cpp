//Works on Linux
// Compile with: g++ client.cpp -o client

#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

const char *fifo_path = "/tmp/my_fifo";

int main() {
    int L, U;
    std::cout << "Enter L: ";
    std::cin >> L;
    std::cout << "Enter U: ";
    std::cin >> U;

    int fd = open(fifo_path, O_WRONLY);
    write(fd, &L, sizeof(L));
    write(fd, &U, sizeof(U));
    close(fd);

    return 0;
}