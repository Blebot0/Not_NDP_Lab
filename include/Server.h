#pragma once

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

namespace sr
{
    class Server{

        private:
            
            int s_socket_;
            int buffer_recv_;
            int buffer_send_;
            int port_;
	        int size_client_;
            int bind_;
	        socklen_t len_;

	        sockaddr_in server_;
            sockaddr_in client_;

            int buff[50];

            std::string ipv4_addr_;

            void Bind();
        public:

            Server(int port);
            ~Server();
            void send();
            void send(int );
            void send(int []);
            
            void recv();
            void recv(int );
            void recv(int []);

    };
} // namespace sr

