#include <windows.h>
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
#define SCK_VERSION 0x0202

int main()
{

    SOCKET ConSocket = INVALID_SOCKET;
    SOCKET ListenSocket = INVALID_SOCKET;
    SOCKADDR_IN address;
    int addrsize = sizeof(address);

    long ok;
    char MESSAGE[200];

    WSADATA wsaData;
    WORD DllVersion;
    DllVersion= MAKEWORD(2,1);
    ok = WSAStartup(DllVersion, &wsaData);

    ConSocket = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_family = AF_INET;
    address.sin_port = htons(10102);

    ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
    bind(ListenSocket, (SOCKADDR*)&address, sizeof(address));
    listen(ListenSocket, SOMAXCONN);

    cout<<"Server waiting for connections\n\n";

    while(true)
    {
        if(ConSocket = accept (ListenSocket, (SOCKADDR*)&address, &addrsize))
        {
            cout<<"Client connected\n";
            ok = recv(ConSocket, MESSAGE, sizeof(MESSAGE), 0);
            string msg;
            msg =  MESSAGE;
            cout<<"Client says:\t"<<msg<<endl;

            string reply;
            cout<<"Enter reply:\t";
            cin>>reply;

            const  char* s = reply.c_str();
            ok  = send(ConSocket,s, 1024, 0);
        }
    }
    return 0;
}
