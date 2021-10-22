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

// int main(){
// 	int s, r, recb, sntb, x;
// 	int ca;
// 	printf("INPUT PORT NUMBER: ");
// 	scanf("%d", &x);
// 	socklen_t len;
// 	struct sockaddr_in server, client;
// 	int buff[50];



// 	printf("\nSOCKET BINDED TO MEMORY ADDRESS");
	
// 	while(1){
// 		recb = recvfrom(s, buff, sizeof(buff), 0, (struct sockaddr*)&client, &ca);
// 		if(recb == -1){
// 			printf("\n MESSAGE RECEIVING FAILED");
// 			close(s);
// 			exit(0);
// 		}
// 		printf("\nMESSAGE RECEIVED");
// 		printf("\n\n");

// 		if(buff[0]==-1){
// 			printf("\nEXITING FROM SERVER....\n");
// 			break;	
// 		}
		
// 		else if(buff[0] == 0){
// 			int size = sizeof(buff)/ sizeof(buff[0]);
// 			int key = buff[size];
// 			for(int i = 1; i<size; i++)
// 			{
// 				if(key == buff[i]){
// 					buff[0] = key;
// 			}
// 		}	
// 		else if(buff[0]==1){
		
// 			int size = sizeof(buff)/sizeof(buff[0]);
// 			for(int i = 1; i<=size; i++)
// 			{
// 				for(int j = i; j<=size; j++){

// 					if(buff[i] > buff[i+1]){

// 						int temp = buff[i];
// 						buff[i] = buff[i+1];
// 						buff[i+1] = temp;
// 					}
// 				}
// 			}
// 		}

// 		else if(buff[0]==2){

// 			int size = sizeof(buff)/sizeof(buff[0]);
//                         for(int i = 1; i<=size; i++)
//                         {
//                                 for(int j = i; j<=size; j++){
					
// 					if(buff[i]<buff[i+1]){

//                                         int temp = buff[i];
//                                         buff[i] = buff[i+1];
//                                         buff[i+1] = temp;
// 					}
//                                 }
//                         }
//                 }

// 		else if(buff[0]==3){
			
// 			int even[50], odd[50], even_pos = 0, odd_pos = 0;
// 			int size = sizeof(buff)/sizeof(buff[0]);
// 			for(int i = 1; i <=size; i++){
// 				if (buff[i]%2==0)
// 				{
// 					even[even_pos]= buff[i];
// 					even_pos++;
// 				}
// 				else{
// 					odd[odd_pos] =buff[i];
// 					odd_pos++;
// 				}
// 			}


// 			for(int i = 1; i<=even_pos;i++)
// 				buff[i] = even[i];
// 			for(int i = size - even_pos + 1; i<=odd_pos; i++)
// 				buff[i] = odd[i];
// 		}

		
// 		sntb = sendto(s, buff, sizeof(buff), 0,(struct sockaddr*)& client, len );
// 		if(sntb==-1){
// 			printf("\n MESSAGE SENDING FAILED");
// 			close(s);
// 			exit(0);
// 		}

// 	}

// 	close(s);

// 	return 0;
// }

