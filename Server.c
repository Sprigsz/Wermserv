#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main()
{
    int server_sock;
    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock == -1) 
    {
        perror("There was an error creating a socket.");
        exit(1);
    }
     
    //bind()
    struct sockaddr_in address; // 
    address.sin_family = AF_INET; // IPV4 should be used
    address.sin_port = htons(8080); // Server will listen on port 8080
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all interfaces.
    bind(server_sock,(struct sockaddr*)&address, sizeof(address));

    if (bind(server_sock,(struct sockaddr*)&address, sizeof(address)) == -1)
    {
        perror("Bind failed");
        exit(1);
    }
    //listen()

    //accept
    return 0;
}
