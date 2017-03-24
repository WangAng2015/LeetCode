#pragma once

extern "C"//告诉C++编译器这是C函数
{
	int socket_send();
	int socket_recv();
}