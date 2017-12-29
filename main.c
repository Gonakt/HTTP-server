#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int status, sockfd, new_fd, byte_count;
    char buf[10000], sep, *req_part;
    struct addrinfo hints, *res, *servinfo;
    socklen_t addr_size;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags - AI_PASSIVE;

    if (status = getaddrinfo(NULL, "3000", &hints, &servinfo) != 0)
    {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    sockfd = socket(res -> ai_family, res -> ai_socktype, res -> ai_protocol);
    bind(sockfd, res -> ai_addr, res -> ai_addrlen);
    listen(sockfd, BACKLOG);
    addr_size = sizeof their_addr;
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
    byte_count = recv(new_fd, buf, sizeof buf, 0);
    if (byte_count == -1)
	perror("recv error: ");
	else
    {
        req_part = strtok(buf, sep);
        if (strcmp(req_part, "GET"))
        {
            req_part = NULL;
            req_part = strtok(buf, sep);

        }
    }
    freeaddrinfo(servinfo);
    return 0;
}