#include "Client.h"

Client::Client()
{
	client = gcnew TcpClient();
}

Client::~Client()
{
	client->Close();
}

Void Client::Connect(String ^IP, int port)
{
	client->Close();
	client = gcnew TcpClient();			// ради нового подключения приходится создавать новый объект
	client->Connect(IP, port);
	stm = client->GetStream();			// связали буфер и сокет 
	reader = gcnew BinaryReader(stm);
	writer = gcnew BinaryWriter(stm);
}

Void Client::Write(String ^message)
{
	writer->Write(message);
}

String^ Client::Read()
{
	return reader->ReadString();
}

bool Client::IsConnected()
{
	return client->Connected;
}


