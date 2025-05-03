#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 256

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // Check if port number is provided
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    // Get the port number from command-line argument
    int PORT = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Set up server address structure
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    // Convert IPv4 address from text to binary (localhost)
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        error("Invalid address / Address not supported");
    }

    // Sending and receiving messages
    while (1) {
        printf("Client: ");
        bzero(buffer, BUFFER_SIZE);
        fgets(buffer, BUFFER_SIZE, stdin);

        // Remove newline character from input
        buffer[strcspn(buffer, "\n")] = 0;

        // Check for termination message
        if (strcmp(buffer, "bye") == 0) {
            printf("Client is disconnecting.\n");
            sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
            break;
        }

        // Send message to the server
        sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

        // Read response from the server
        bzero(buffer, BUFFER_SIZE);
        socklen_t serv_len = sizeof(serv_addr);
        n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&serv_addr, &serv_len);
        if (n > 0) {
            printf("Server: %s\n", buffer);

            // Check for termination message from server
            if (strcmp(buffer, "bye") == 0) {
                printf("Server has disconnected.\n");
                break;
            }
        } else {
            printf("Error receiving message.\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}

