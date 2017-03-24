#include<WinSock2.h>
#include<string.h>
#include<stdio.h>

int socket_send()
{
	//��ʼ��socket
	DWORD ver;
	WSADATA wsaDATA;
	ver = MAKEWORD(1, 1);//ȷ����ʲô�汾��socket���汾1.1
	WSAStartup(ver, &wsaDATA);
	//��ʼ��socket���

	//����һ��socket
	//��һ������ָ��socketʹ��ʲôЭ��(AF_INET��ʾTCP/IPЭ��)
	//�ڶ�������ָ��ʹ��UDPЭ�飨TCP/IPЭ���Ǹ�Э���壩
	SOCKET st = socket(AF_INET,SOCK_DGRAM,0);//����һ��socket
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));//��ʼ���ṹaddr
	addr.sin_family = AF_INET;//ָ��Э��
	addr.sin_port = htons(8080);//ָ���˿ں�
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");//���շ�IP��127.0.0.1������IP��ַ��

	char buf[1024] = { 0 };
	strcpy(buf, "Hello Ang");
	//����UDP����
	size_t rc = sendto(st, buf, strlen(buf), 0, (struct sockaddr *)&addr, sizeof(addr));//���ط�����������
	closesocket(st);//ʹ�������Ҫ�ر�socket
	WSACleanup();//�ͷ���Դ

	return rc;

}

int socket_recv()
{
	//��ʼ��socket
	DWORD ver;
	WSADATA wsaDATA;
	ver = MAKEWORD(1, 1);//ȷ����ʲô�汾��socket���汾1.1
	WSAStartup(ver, &wsaDATA);
	//��ʼ��socket���

	//����һ��socket
	//��һ������ָ��socketʹ��ʲôЭ��(AF_INET��ʾTCP/IPЭ��)
	//�ڶ�������ָ��ʹ��UDPЭ�飨TCP/IPЭ���Ǹ�Э���壩
	SOCKET st = socket(AF_INET, SOCK_DGRAM, 0);//����һ��socket
	struct sockaddr_in addr;
	memset(&addr, 0, sizeof(addr));//��ʼ���ṹaddr
	addr.sin_family = AF_INET;//ָ��Э��
	addr.sin_port = htons(7976);//ָ���˿ں�
	addr.sin_addr.s_addr = htonl(INADDR_ANY);//���ܷ�����ָ��IP��ַ
	int rc = 0;
	if (bind(st, (struct sockaddr *)&addr, sizeof(addr)) == -1)//���˿ںźͳ����,��ʧ�ܷ���-1,�˿ڿ����ѱ���������ʹ��
	{
		char buf[1024] = { 0 };
		struct sockaddr_in sendaddr;//������յ�IP
		memset(&sendaddr, 0, sizeof(sendaddr));
		int len = sizeof(sendaddr);
		//����UDP����
		rc = recvfrom(st, buf, strlen(buf), 0, (struct sockaddr *)&sendaddr, &len);
		printf("%s\n", buf);
	}
	closesocket(st);//ʹ�������Ҫ�ر�socket
	WSACleanup();//�ͷ���Դ

	return rc;

}
