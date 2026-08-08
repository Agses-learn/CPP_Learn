#include<iostream>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <unistd.h>
#include<cstring>
#include <thread>
#include <chrono>
using namespace std;

int main()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (sockaddr*)&serverAddr, sizeof(serverAddr));
    std::cout << "UDP Server listening on port 8080..." << std::endl;

    char buffer[1024];
    sockaddr_in clientAddr{};
    socklen_t addrlen = sizeof(clientAddr);

    while(1)
    {
        ssize_t bytes = recvfrom(sockfd, buffer, sizeof(buffer), 0, (sockaddr*)&clientAddr, &addrlen);
        buffer[bytes] = '\0';

        std::cout << "Client[" << inet_ntoa(clientAddr.sin_addr) << "]: " << buffer << std::endl;
    }
}