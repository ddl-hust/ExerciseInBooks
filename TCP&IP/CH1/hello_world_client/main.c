#include<winsock2.h>
#include<stdio.h>
#include<stdlib.h>
void ErrorHandle(char* message);
int main(int argc, char* argv[]) {
	WSADATA wsdata;
	SOCKET hServSock;
	SOCKADDR_IN servaddr;
	char message[30];
	int strlen = 0;
	int idx = 0, readlen = 0;
	if (argc != 3) {
		printf("usage : %s <ip> <port> \n", argv[0]);
		exit(1);
	}
	if (WSAStartup(MAKEWORD(2, 2), &wsdata) != 0) ErrorHandle("socket start error");

	hServSock = socket(PF_INET, SOCK_STREAM, 0);
	if (hServSock == INVALID_SOCKET) ErrorHandle("socket() error");
	memset(&servaddr, 0, sizeof(servaddr)); 
											
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = inet_addr(argv[1]); //将字符串点分号字符串表示的ipv4地址转换为32bit
	servaddr.sin_port = htons(atoi(argv[2]));

	if (connect(hServSock, (SOCKADDR *)&servaddr, sizeof(servaddr)) ==SOCKET_ERROR)
		ErrorHandle("connect( error!");
	//once receive a char
	while (readlen=recv(hServSock,&message[idx++],1,0))
	{	
		if (readlen == -1) ErrorHandle("recieive() error");
		strlen += readlen;
		if (message[idx - 1] == '\0') break;

	}
	closesocket(hServSock);
	WSACleanup();
	return 0;
}

void ErrorHandle(char* message) {
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

