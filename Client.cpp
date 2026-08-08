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
    int i = 0;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080);
    inet_pton(AF_INET, "0.0.0.0", &serverAddr.sin_addr);

    const char* msg = "Hello Xueyao.Sun, this is an UDP client!";

    do
    {
        sendto(sockfd, msg, strlen(msg), 0, (sockaddr*)&serverAddr, sizeof(serverAddr));
        std::cout << "Message sent." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        i++;
    }while(i<=20);
    closesocket(sockfd);
    std::cout << "Close socket now." << std::endl;
}