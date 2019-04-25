#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <stdio.h>
#include <string>

#define SCK_VERSION 0x0202

using namespace std;
int main()
{
    SOCKET sock = INVALID_SOCKET;
    SOCKADDR_IN address;

    long ok;
    char message[200];
    WSADATA WSD;
    WORD DllVersion;
    DllVersion = MAKEWORD(2,1);
    ok = WSAStartup(DllVersion, &WSD);

    while(true)
    {
        sock = socket(AF_INET, SOCK_STREAM, 0);
        address.sin_addr.s_addr = inet_addr("127.0.0.1");
        address.sin_family = AF_INET;
        address.sin_port= htons(10102);

        connect(sock, (SOCKADDR*)&address, sizeof(address));
        string msg;
        cout<<"Enter message:\t";
        cin>>msg;
        const char* s = msg.c_str();
        ok = send(sock, s, 1024, 0);

        ok = recv(sock, message, sizeof(message), 0);
        string reply;
        reply = message;
        cout<<"Server says:\t"<<reply<<endl;
    }
    return 0;
}
