/* This file should implement the getTime() function. 
   The getTime() function should send request (over socket) to the time manager service (daemon) and get the response.
   This function should not directly read the time from the system */


#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define PORT 9999

int64_t getTime() {

    int client_fd = {0};

    client_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if(client_fd < 0) {
        perror("");
        exit(EXIT_FAILURE);
    }

    sockaddr_in client_addr;

    client_addr.sin_family = AF_INET;
    client_addr.sin_port = htons(PORT);
    client_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if((connect(client_fd, (struct sockaddr*)&client_addr, sizeof(client_addr))) < 0) {
        perror("");
        exit(EXIT_FAILURE);
    }
    
    char request[20] = {0};
    std::cout << "Choose your request (1.time 2.exit)" << std::endl;
    std::cin >> request ;

    send(client_fd, request, 20, 0);

    char message[20] = {0};
    recv(client_fd, message, 20, 0);
   
    int64_t epoch_time = atoi(message); 
    
    close(client_fd);

    return epoch_time;
}
