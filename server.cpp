#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h> // needed for inet_aton() 

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        std::cerr << "Error creating socket" << std::endl;
        return EXIT_FAILURE;
    }

    // Set up server address structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Port number
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        std::cerr << "Error binding socket" << std::endl;
        return EXIT_FAILURE;
    }

    // Listen for incoming connections
    if (listen(serverSocket, 5) == -1) {
        std::cerr << "Error listening on socket" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Server listening on port 12345..." << std::endl;

    // Accept incoming connection
    clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
    if (clientSocket == -1) {
        std::cerr << "Error accepting connection" << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "Connection accepted from " << inet_ntoa(clientAddr.sin_addr) << std::endl;

    // Communication with the client
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytesRead;

    while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
        std::cout << "Received: " << buffer << std::endl;
        send(clientSocket, buffer, bytesRead, 0);
        memset(buffer, 0, sizeof(buffer));
    }

    close(clientSocket);
    close(serverSocket);

    return 0;
}
