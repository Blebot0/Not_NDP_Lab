#include "Client.h"

using namespace cl;

Client::Client(int port, const std::string& ipv4_addr):port_(port), ipv4_addr_(ipv4_addr) 
{
    s_socket_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (s_socket_ == -1)
    {
            std::cout<<"\nSOCKET ERROR";
            //Recovery
    }

    std::cout<<"SOCKET CREATED\n";

    server_.sin_family = AF_INET;
    server_.sin_port = htons(port_);
    server_.sin_addr.s_addr = inet_addr(ipv4_addr_.c_str());
    size_server_ = sizeof(server_);
    len_ = sizeof(server_);
}


void Client::send(int buffer[]){

    buffer_send_ = sendto(s_socket_, buffer, sizeof(buffer), 0, (struct sockaddr*) &server_, size_server_);
    if(buffer_send_ == -1){
        printf("\nMESSAGE SENDING FAILED");
            //Recovery

		close(s_socket_);
    }
}
void Client::send(int buffer){

    buffer_send_ = sendto(s_socket_, &buffer, sizeof(buffer), 0, (struct sockaddr*) &server_, size_server_);
    if(buffer_send_ == -1){
        printf("\nMESSAGE SENDING FAILED");
            //Recovery

		close(s_socket_);
    }
}

void Client::recv(int buffer[]){
    buffer_recv_ = recvfrom(s_socket_, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_, &len_);
        if(buffer_recv_ == -1){
            std::cout<<"\nMESSAGE NOT SENT";
            //Recovery
 
            close(s_socket_);
        }
        std::cout<<"\nMESSAGE RECEIVED";
}

void Client::recv(int buffer){
    buffer_recv_ = recvfrom(s_socket_, &buffer, sizeof(buffer), 0, (struct sockaddr*)&client_, &len_);
        if(buffer_recv_ == -1){
            std::cout<<"\nMESSAGE NOT SENT";
            //Recovery
 
            close(s_socket_);
        }
        std::cout<<"\nMESSAGE RECEIVED";
}

Client::~Client(){
    close(s_socket_);
}