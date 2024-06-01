#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in server_addr, new_addr;
    socklen_t addr_size;
    char buffer[1024];
    int ackFrame;

    // Create a socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("Socket creation error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding error");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) == 0) {
        printf("Listening...\n");
    } else {
        perror("Listening error");
        exit(1);
    }

    addr_size = sizeof(new_addr);
    new_socket = accept(server_fd, (struct sockaddr*)&new_addr, &addr_size);

    while (1) {
        // Receive frame from the client
        recv(new_socket, buffer, sizeof(buffer), 0);
        ackFrame = atoi(buffer);
        printf("Received frame %d\n", ackFrame);

        // Send acknowledgment back to the client
        sprintf(buffer, "%d", ackFrame);
        send(new_socket, buffer, sizeof(buffer), 0);
        printf("Acknowledgement for frame %d sent\n", ackFrame);
    }

    close(new_socket);
    close(server_fd);
    return 0;
}

