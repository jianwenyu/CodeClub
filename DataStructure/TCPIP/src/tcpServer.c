#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

#define PORT 8080
#define MAX 80

void func(int sockfd) 
{ 
    char buff[MAX]; 
    int n; 
    // infinite loop for chat 
    for (;;) { 
        bzero(buff, MAX); 
  
        // read the message from client and copy it in buffer 
        read(sockfd, buff, sizeof(buff)); 
        // print buffer which contains the client contents 
        printf("From client: %s\t To client : ", buff); 
        bzero(buff, MAX); 
        n = 0; 
        // copy server message in the buffer 
        while ((buff[n++] = getchar()) != '\n') 
            ; 
  
        // and send that buffer to client 
        write(sockfd, buff, sizeof(buff)); 
  
        // if msg contains "Exit" then server exit and chat ended. 
        if (strncmp("exit", buff, 4) == 0) { 
            printf("Server Exit...\n"); 
            break; 
        } 
    } 
} 

int main(int argc, char **argv)
{
    int server_fd;
    int new_socket;
    int valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    //char buffer[1024] = {0};
    char *hello = "hello from server";

    /** Creating socket file descriptor
     *  1. AF_INET is belong to IP protocol family. 
     *  2. 
     *      -SOCK_STREAM: TCP (reliable, connection oriented) 
     *      -SOCK_DGRAM: UDP (unreliable, connectionless)
     *  3. protocal: protocal value for internet protocol (IP)
     */

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        printf("TCP/IP Server error: Socket create failed.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("TCP/IP Server: File descriptor create successfully.\n");
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Forcefully attaching socekt to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
    }else{
        printf("TCP/IP Server: bind successfully.\n");
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }else{
        printf("TCP/IP Server: listening.\n");
    }

    if (new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen) < 0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }else{
        printf("TCP/IP Server: accept successfully. fd:%d\n",new_socket);
    }
    
    func(new_socket);
    /*
    valread = read(new_socket, buffer, 1024);
    printf("%d received\n", valread);
    printf("%s\n", buffer);
    write(new_socket, hello, strlen(hello));
    printf("hello message sent \n");
    */
    return 0;
}