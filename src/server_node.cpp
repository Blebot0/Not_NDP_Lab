#include "Server.h"

int main(){
    sr::Server sr(5000);
    int buffer[500];
    sr.recv(buffer);

    return 0;
}