#include "Client.h"

int main(){
    cl::Client cl(5000, "127.0.0.1");

    int a[] = {23, 243, 234, 24567, 648};
    cl.send(a);

    return 0;
}