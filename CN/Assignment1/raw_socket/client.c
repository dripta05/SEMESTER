#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 12345
#define BUF_SIZE 1024

unsigned short checksum(void *b, int len) {
  unsigned short *buf = b;
  unsigned int sum = 0;
  unsigned short result;
  for (sum = 0; len > 1; len -= 2)
    sum += *buf++;
  if (len == 1)
    sum += *(unsigned char *)buf;
  sum = (sum >> 16) + (sum & 0xFFFF);
  sum += (sum >> 16);
  result = ~sum;
  return result;
}

int main() {
  int sockfd;
  struct sockaddr_in addr;
  char buffer[BUF_SIZE];
  char packet[BUF_SIZE];

  // Create a raw socket
  sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
  if (sockfd < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  // Set socket options to include IP header
  int one = 1;
  const int *val = &one;
  if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, val, sizeof(one)) < 0) {
    perror("Error setting IP_HDRINCL");
    exit(EXIT_FAILURE);
  }

  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(PORT);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  struct iphdr *ip_header = (struct iphdr *)packet;
  struct sockaddr_in dest;
  dest.sin_family = AF_INET;
  dest.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Initialize IP header
  ip_header->ihl = 5;
  ip_header->version = 4;
  ip_header->tos = 0;
  ip_header->id = htonl(54321);
  ip_header->frag_off = 0;
  ip_header->ttl = 255;
  ip_header->protocol = IPPROTO_RAW;
  ip_header->check = 0;
  ip_header->saddr = inet_addr("127.0.0.1");
  ip_header->daddr = inet_addr("127.0.0.1");

  printf("Client started. Send messages to the server.\n");

  while (1) {
    printf("Enter your message (type 'exit' to quit): ");
    fgets(packet + sizeof(struct iphdr), BUF_SIZE - sizeof(struct iphdr),
          stdin);

    // Remove newline character
    int len = strcspn(packet + sizeof(struct iphdr), "\n");
    (packet + sizeof(struct iphdr))[len] = '\0';

    // Check if user wants to exit
    if (strcmp(packet + sizeof(struct iphdr), "exit") == 0) {
      printf("Client disconnected.\n");
      break;
    }

    // Set the total length field in the IP header
    int payload_len = strlen(packet + sizeof(struct iphdr));
    int total_len = sizeof(struct iphdr) + payload_len;
    ip_header->tot_len = htons(total_len);

    // Calculate the checksum
    ip_header->check = 0;
    ip_header->check = checksum((unsigned short *)packet, sizeof(struct iphdr));

    // Send the packet
    if (sendto(sockfd, packet, total_len, 0, (struct sockaddr *)&dest,
               sizeof(dest)) < 0) {
      perror("sendto failed");
      continue;
    }

    printf("Message sent: %s\n", packet + sizeof(struct iphdr));

        char* sentMessage = packet + sizeof(struct iphdr);

    memset(buffer, 0, BUF_SIZE);

    struct sockaddr_in sender;
    socklen_t sender_len = sizeof(sender);

    ssize_t bytes_received = recvfrom(sockfd, buffer, BUF_SIZE, 0,
                                      (struct sockaddr *)&sender, &sender_len);

    if (bytes_received < 0) {
      perror("recvfrom failed");
      continue;
    }

    // Extract the IP header and payload
    struct iphdr *resp_ip = (struct iphdr *)buffer;
    int ip_header_len = resp_ip->ihl * 4;
    char *response_payload = buffer + ip_header_len;
    if(strcmp(sentMessage, response_payload)!=0)
    printf("Server: %s\n", response_payload);
  }

  // Clean up
  close(sockfd);

  return 0;
}
