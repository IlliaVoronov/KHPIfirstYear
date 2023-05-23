// g++ server.cpp -o server


#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[1024];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket." << std::endl;
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        std::cerr << "Error binding socket." << std::endl;
        return 1;
    }

    int L, U;
    recvfrom(sockfd, &L, sizeof(L), 0, (struct sockaddr *)&client_addr, &addr_len);
    recvfrom(sockfd, &U, sizeof(U), 0, (struct sockaddr *)&client_addr, &addr_len);

    long long sum = 0, product = 1;
    for (int i = L; i <= U; ++i) {
        sum += i;
        product *= i;
    }

    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Product: " << product << std::endl;

    close(sockfd);
    return 0;
}
