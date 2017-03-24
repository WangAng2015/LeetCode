#include<WinSock2.h>
#include<string.h>
#include<stdio.h>

int socket_send()
{
	//初始化socket
	DWORD ver;
	WSADATA wsaDATA;
	ver = MAKEWORD(1, 1);//确定用什么版本的socket，版本1.1
	WSAStartup(ver, &wsaDATA);
	//初始化socket完成

	//建立一个socket
	//第一个参数指定socket使用什么协议(AF_INET表示TCP/IP协议)
	//第二个参数指定使用UDP协议（TCP/IP协议是个协议族）
	SOCKET st = socket(AF_INET,SOCK_DGRAM,0);//定义一个socket
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));//初始化结构addr
	addr.sin_family = AF_INET;//指定协议
	addr.sin_port = htons(8080);//指定端口号
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");//接收方IP，127.0.0.1代表本机IP地址，

	char buf[1024] = { 0 };
	strcpy(buf, "Hello Ang");
	//发送UDP数据
	size_t rc = sendto(st, buf, strlen(buf), 0, (struct sockaddr *)&addr, sizeof(addr));//返回发出的数据数
	closesocket(st);//使用完后需要关闭socket
	WSACleanup();//释放资源

	return rc;

}

int socket_recv()
{
	//初始化socket
	DWORD ver;
	WSADATA wsaDATA;
	ver = MAKEWORD(1, 1);//确定用什么版本的socket，版本1.1
	WSAStartup(ver, &wsaDATA);
	//初始化socket完成

	//建立一个socket
	//第一个参数指定socket使用什么协议(AF_INET表示TCP/IP协议)
	//第二个参数指定使用UDP协议（TCP/IP协议是个协议族）
	SOCKET st = socket(AF_INET, SOCK_DGRAM, 0);//定义一个socket
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));//初始化结构addr
	addr.sin_family = AF_INET;//指定协议
	addr.sin_port = htons(7976);//指定端口号
	addr.sin_addr.s_addr = htonl(INADDR_ANY);//接受方不需指定IP地址
	int rc = 0;
	if (bind(st, (struct sockaddr *)&addr, sizeof(addr)) == -1)//将端口号和程序绑定,绑定失败返回-1,端口可能已被其他程序使用
	{
		char buf[1024] = { 0 };
		struct sockaddr_in sendaddr;//定义接收的IP
		memset(&sendaddr, 0, sizeof(sendaddr));
		int len = sizeof(sendaddr);
		//接收UDP数据
		rc = recvfrom(st, buf, strlen(buf), 0, (struct sockaddr *)&sendaddr, &len);
		printf("%s\n", buf);
	}
	closesocket(st);//使用完后需要关闭socket
	WSACleanup();//释放资源

	return rc;

}
