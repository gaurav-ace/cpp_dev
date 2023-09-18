#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 12345
#define MAX_BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char message[MAX_BUFFER_SIZE];

    // Create socket
    if ((client_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        std::cout << "Socket creation failed \n";
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &server_address.sin_addr) <= 0) {
        std::cout << "Invalid address \n";
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        std::cout << "Connection failed \n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Connected to server \n";

    // Send a message to the server
    std::string buff;
    std::getline(std::cin, buff);
    
    //strcpy(message, "Hello, server!");

    send(client_socket, buff.c_str(), buff.size(), 0);

    // Receive a response from the server
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0';
        std::cout << "Received from server: " << buffer << "\n";
    } else {
        std::cout << "Receive failed \n";
    }

    // Close the socket
    close(client_socket);

    return 0;
}
