#include<winsock2.h>
#include<stdio.h>
#include<stdlib.h>

void ErrorHandle(char* message);

int main(int argc, char* argv[]) {
	WSADATA wsdata;
	SOCKET hServSock, hClientSock;
	SOCKADDR_IN servaddr, clntaddr;
	int size_client_addr=sizeof(clntaddr);
	char message[] = "hello world";
	if (argc != 2) {
		printf("usage : %s <port> \n", argv[0]);
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsdata) != 0) ErrorHandle("socket start error"); //固定套路

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET) ErrorHandle("socket() error");
	memset(&servaddr, 0, sizeof(servaddr)); //初始化为0
	//地址分配协议
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr= htonl(INADDR_ANY); //hton host->network order long 
	servaddr.sin_port = htons(atoi(argv[1]));

	if (bind(hServSock, (SOCKADDR*)&servaddr, sizeof(servaddr)) == SOCKET_ERROR) ErrorHandle("bind() error");
	if (listen(hServSock, 5) == SOCKET_ERROR) ErrorHandle("listen error");
	
	hClientSock = accept(hServSock, (SOCKADDR*)&hClientSock, sizeof(hClientSock)); //接收函数
	if (hClientSock == INVALID_SOCKET) ErrorHandle("accept error");
	send(hClientSock, message, sizeof(message), 0);
	closesocket(hServSock);
	closesocket(hClientSock);
	return 0;
}
void ErrorHandle(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

