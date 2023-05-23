//g++ client.cpp -o client

#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error creating socket." << std::endl;
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int L, U;
    std::cout << "Enter the lower limit (L): ";
    std::cin >> L;
    std::cout << "Enter the upper limit (U): ";
    std::cin >> U;

    sendto(sockfd, &L, sizeof(L), 0, (struct sockaddr *)&server_addr, addr_len);
    sendto(sockfd, &U, sizeof(U), 0, (struct sockaddr *)&server_addr, addr_len);

    close(sockfd);
    return 0;
}
