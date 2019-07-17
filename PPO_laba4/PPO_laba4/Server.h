#pragma once

#include <cliext/utility>
#include <cliext/algorithm>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace cliext;

ref class Server
{
private:
	TcpListener ^listener;
	Socket ^socket;

public:
	Server();
	~Server();

	pair<IPAddress^ , int>^ Connect();	// ищем подходящий адрес и порт по умолчанию
	Void WaitClient();
};

