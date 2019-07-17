#pragma once

#include <cliext/vector>

using namespace System;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::IO;
using namespace System::Text;
using namespace cliext;

ref class Client
{
private:
	TcpClient ^client;
	Stream ^stm;				// получаем и передаем данные  
	BinaryReader ^reader;
	BinaryWriter ^writer;

public:
	Client();
	~Client();

	Void Connect(String^ , int);	
	Void Write(String^ );
	String^ Read();
	bool IsConnected();
};

