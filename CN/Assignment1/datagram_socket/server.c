#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Port No. not provided. Program terminated\n");
        exit(1);
    }

    int sockfd, n;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_len = sizeof(cli_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        error("Error opening socket.");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    int portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("Binding failed");
    }

    while (1) {
        bzero(buffer, 256);
        n = recvfrom(sockfd, buffer, 255, 0, (struct sockaddr *)&cli_addr, &cli_len);
        if (n < 0) {
            error("Error on reading.");
        }

        // Remove newline character from input
        buffer[strcspn(buffer, "\n")] = 0;

        printf("CLient: %s\n", buffer);

        // Check for termination message
        if (strcmp(buffer, "bye") == 0) {
            printf("Client has disconnected.\n");
            char* msg = "bye";
            sendto(sockfd, msg, strlen(msg), 0, (struct sockaddr *)&cli_addr, cli_len);
            break;
        }

        printf("Server:");
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);

        // Remove newline character from input
        buffer[strcspn(buffer, "\n")] = 0;

        n = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&cli_addr, cli_len);
        if (n < 0) {
            error("Error on writing");
        }
        if (strcmp(buffer, "bye") == 0) {
            printf("Server is disconnecting.\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}

