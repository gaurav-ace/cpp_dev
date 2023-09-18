#include <iostream>
#include <stdlib.h>  // type conversions and some predefined genral macros
#include <string.h>
#include <unistd.h>  // used for some type posix based API calls
#include <arpa/inet.h> 

#define PORT 12345
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        std::cout << "Socket creation failed \n";
        exit(EXIT_FAILURE);
    }

    // Configure server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(PORT);

    // Bind socket to the specified address and port
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        std::cout << "Bind failed \n";
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        std::cout << "Listen failure \n";
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    // Accept incoming connection
    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) == -1) {
        std::cout << "Accept failed \n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Client connected \n";

    // Receive data from client
    ssize_t bytes_received;
    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_received] = '\0';
        std::cout << "Received: " << buffer << "\n";

        // Send a response to the client
        send(client_socket, buffer, strlen(buffer), 0);
    }

    if (bytes_received == -1) {
        std::cout << "Receive failed \n";
        exit(EXIT_FAILURE);
    }

    // Close sockets
    close(client_socket);
    close(server_socket);

    return 0;
}
