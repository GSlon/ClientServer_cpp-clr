#include "Server.h"



Server::Server()
{


}

Server::~Server()
{
	listener->Stop();
}

pair<IPAddress^, int>^ Server::Connect()
{
	array<IPAddress^> ^localIP = Dns::GetHostAddresses(Dns::GetHostName());
	
	for each (IPAddress^ address in localIP)
	{
		if (address->AddressFamily == AddressFamily::InterNetwork)
		{
			listener = gcnew TcpListener(address, 8001);
			listener->Start();

			return gcnew pair<IPAddress^, int>(address, 8001);
		}
	}

	throw gcnew Exception("all IPaddress are busy");
}

Void Server::WaitClient()
{
	socket = listener->AcceptSocket();
}
