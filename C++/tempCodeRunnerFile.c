#include<stdio.h>
#include<winsock2.h>
#pragma comment(lib,"ws2_32.lib")

int main()
{
    WSADATA ws;
    int result;
    result=WSAStartup(MAKEWORD(2,2),&ws);
    if(result==0)
    {
        printf("initialised");
        WSACleanup();
    }
    else{
        printf("not initilaised");

    }
    return 0;
}