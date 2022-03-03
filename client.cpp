#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char * argv[])
{
    if(argc!=3){
        printf("Using:./client ip port\nExample:./client 127.0.0.1 5005\n\n"); return -1;
    }
    // *****  step 1: create client-side socket ******* //
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket"); return -1;
    }
    // *****  step 2: send connection request to server ******* //
    struct hostent* h;
    if ((h = gethostbyname(argv[1]))==0){ //server ip address
        printf("gethostbyname failed.\n"); close(sockfd); return -1;
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2])); //server port
    memcpy(&servaddr.sin_addr, h->h_addr, h->h_length);
    if (connect(sockfd, (struct sockaddr * )&servaddr, sizeof(servaddr)) != 0){
        perror("connect"); close(sockfd); return -1;
    }

    char buffer[1024];
    // *****  step 3: send one packet to server, wait for response, then send the next packet ******* //
    for(int ii = 0; ii < 3; ii++){
        int iret;
        memset(buffer, 0, sizeof(buffer));
        sprintf(buffer, "This is the %d th, id is %03d.", ii+1, ii+1);
        if ((iret = send(sockfd, buffer, strlen(buffer), 0))<= 0)
        {
            perror("send"); break;
        }
        printf("send: %s\n", buffer);
    }
}