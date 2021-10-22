#include "Server.h"

using namespace sr;

Server::Server(int port):port_(port){
	s_socket_ = socket(AF_INET, SOCK_DGRAM, 0);
	if (s_socket_==-1)
	{
		printf("\nSOCKET ERROR");
		exit(0);
	}

	printf("\nSOCKET CREATED");

	server_.sin_family = AF_INET;
	server_.sin_port = htons(port_);
	server_.sin_addr.s_addr = htonl(INADDR_ANY);
	len_ = sizeof(client_);
	size_client_ = sizeof(client_);
    Bind();
}

void Server::Bind(){
    bind_ = bind(s_socket_, (struct sockaddr*)& server_, sizeof(server_));
	if(bind_ == -1){
		printf("\nBINDING ERROR");
        //Recovery
	}
    std::cout<<"\nSOCKET BINDED";
}

void Server::send(int buffer[]){

    buffer_send_ = sendto(s_socket_, buffer, sizeof(buffer), 0, (struct sockaddr*) &server_, size_client_);
    if(buffer_send_ == -1){
        printf("\nMESSAGE SENDING FAILED");
            //Recovery

		close(s_socket_);
    }
}
void Server::send(int buffer){

    buffer_send_ = sendto(s_socket_, &buffer, sizeof(buffer), 0, (struct sockaddr*) &server_, size_client_);
    if(buffer_send_ == -1){
        printf("\nMESSAGE SENDING FAILED");
            //Recovery

		close(s_socket_);
    }
}

void Server::recv(int buffer[]){
    buffer_recv_ = recvfrom(s_socket_, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_, &len_);
        if(buffer_recv_ == -1){
            std::cout<<"\nMESSAGE NOT SENT";
            //Recovery
 
            close(s_socket_);
        }
        
        for (int i = 0; i < sizeof(buffer)/sizeof(buffer[0]); i++)
        {
            std::cout<<buffer[i]<<"\n";
        }
                
        std::cout<<"\nMESSAGE RECEIVED\n";
}

void Server::recv(int buffer){
    buffer_recv_ = recvfrom(s_socket_, &buffer, sizeof(buffer), 0, (struct sockaddr*)&client_, &len_);
        if(buffer_recv_ == -1){
            std::cout<<"\nMESSAGE NOT SENT";
            //Recovery
 
            close(s_socket_);
        }
        std::cout<<"\nMESSAGE RECEIVED";
}

Server::~Server(){
    close(s_socket_);
}