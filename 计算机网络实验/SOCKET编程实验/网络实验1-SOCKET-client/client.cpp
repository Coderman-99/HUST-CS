#pragma once
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <ws2tcpip.h>
#include "winsock2.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <sys/types.h>
#include <fstream>
#pragma comment(lib,"ws2_32.lib")

using namespace std;

void main() {
	//initialize socket
	WSADATA wsadata;
	WORD version = MAKEWORD(2, 2);
	char buff[4032];
	SOCKET socket_ = WSAStartup(version, &wsadata);

	if (socket_!=0) 
		printf("winsock cannot be initialized!\n");
	else
		printf("winsock is initialized!\n");

	//create socket
	SOCKET client_sock;
	sockaddr_in server_addr, client_addr;
	client_sock = socket(AF_INET, SOCK_STREAM, 0);

	if (client_sock != INVALID_SOCKET)			//INVALID_SOCKET value is -1
		printf("socket create success!\n");
	else printf("socket cannot be created");

	//set client port and ip and binding
	client_addr.sin_family = AF_INET;
	client_addr.sin_port = htons(INADDR_ANY);
	client_addr.sin_addr.S_un.S_addr = INADDR_ANY;
	SOCKET bind_client_sock = bind(client_sock, (sockaddr*)&client_addr, sizeof(client_addr));
	if (bind_client_sock != SOCKET_ERROR)				//SOCKET_ERROR value is -1
		printf("socket binding success!\n");
	else printf("socket binding failed\n");

	//set server's ip and port
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(5050);
	server_addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	SOCKET connect_server_sock = connect(client_sock, (sockaddr*)&server_addr, sizeof(server_addr));
	if (connect_server_sock == SOCKET_ERROR)
		printf("connect to server failed!\n");
	else printf("connect to server success\n");
	string message;
	do {
		cout << "\nPlease input your message:";
		cin >> message;

		//send data to server
		int send_mes = send(client_sock, message.c_str(), message.length(), 0);
		if (send_mes == SOCKET_ERROR) {
			printf("Send to server failed\n");
			closesocket(client_sock);
			WSACleanup();
			return;
		}
		char buf[4096];
		memset(buf, '\0', 4096);
		recv(client_sock, buf, 4096, 0);
		printf("%s", buf);
	} while (message != "quit");
	closesocket(client_sock);
	WSACleanup();
}