#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <thread>
#include <mutex>
#define PORT 9999

int socket_fd = {0};
int client_fd = {0};

void processTheClientRequests () {

    std::mutex mtx;

    mtx.lock();
    while (true) {

        std::cout << "waiting for client connection...\n" << std::endl;
        client_fd = accept(socket_fd, NULL, NULL);

        if (client_fd < 0) {
            perror("");
            exit(EXIT_FAILURE);
        }

        std::cout << "connected successfully\n" << std::endl;
        char message[20] = {0};

        
        recv(client_fd, message, 20, 0);

        if(strcmp(message,"time") == 0) {
        
            int64_t current_time = static_cast<int64_t> (time(NULL));
            
            std::string c_time = std::to_string(current_time);

            send(client_fd, c_time.c_str(), c_time.size(), 0);

        }
        else {
           std::cout << "Unable to process the request.....TRY AGAIN...." << std::endl;
        }

        close(client_fd);
    }
    close(socket_fd);

    mtx.unlock();

}
int main() {

    socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (socket_fd < 0) {
        perror("");
        exit(EXIT_FAILURE);
    }

    sockaddr_in server_addr,client_addr;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(bind(socket_fd, (struct sockaddr*)&(server_addr), sizeof(server_addr)) < 0) {
        perror("");
        exit(EXIT_FAILURE);
    }

    listen(socket_fd,5);

    std::thread t1(processTheClientRequests);
    t1.join();

    return 0;
}

