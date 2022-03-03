#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc!=2)
    {
        printf("Using:./server port\nExample:./server 5005\n\n"); return -1;
    }
    // *****  step 1: create server-side socket ******* //
    int listenfd;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0))==-1){
        perror("socket");
        return -1;
    }
    // *****  step 2: bind socket to server address and port number ******* //
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //any ip address
    //servaddr.sin_addr.s_addr = inet_addr("192.168.190.134"); //specific ip address
    servaddr.sin_port = htons(atoi(argv[1])); //specific port number
    if (bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0)
    {
        perror("bind");
        close(listenfd);
        return -1;
    }
    // *****  step 3 listen to socket ******* //
    if(listen(listenfd, 5) !=0 ) {
        perror("listen"); close(listenfd); return -1;
    }
    // *****  step 4 accept connection from clients ******* //
    int clientfd;
    int socklen = sizeof(struct sockaddr_in);
    struct sockaddr_in clientaddr;
    clientfd = accept(listenfd, (struct sockaddr *)&clientaddr, (socklen_t*)&socklen);
    printf("client (%s) is connected.\n", inet_ntoa(clientaddr.sin_addr));
    // *****  step 5 receive  from client's packet, and replies OK ******* //
    char buffer[1024];
    while (1)
    {
        int iret;
        memset(buffer, 0, sizeof(buffer));
        if ((iret=recv(clientfd, buffer, sizeof(buffer), 0)) <= 0){
            printf("iret = %d\n", iret); break;
        }
        printf("receive: %s\n", buffer);

        strcpy(buffer, "OK"); 
        if ((iret=send(clientfd, buffer, strlen(buffer), 0)) <= 0){
            perror("send"); break;
        }
        printf("send: %s\n", buffer);

    }



}