#pragma once

#include <string.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>

namespace cl{

    class Client{

        private:
            
            int s_socket_;
            int buffer_recv_;
            int buffer_send_;
            int port_;
	        int size_server_;
	        socklen_t len_;

	        sockaddr_in server_;
            sockaddr_in client_;

            int buff[50];

            std::string ipv4_addr_;

        public:

            Client(int port, const std::string &ipv4_addr);
            ~Client();
            void send();
            void send(int );
            void send(int []);
            
            void recv();
            void recv(int );
            void recv(int []);


    };
} // namespace cl
