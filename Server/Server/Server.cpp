#include "stdafx.h"
#include <cliext/algorithm>
#include <cliext/utility>
/*   Server Program    */

using namespace System;
using namespace System::Text;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace cliext;
using namespace System::IO;
using namespace System::Threading;

// все элементы меньше N?
String^ Count(String ^numbers)
{
	array<String^> ^SplitNum  = numbers->Split(' ');

	int end = SplitNum->Length - 1;
	int N = Convert::ToInt32(SplitNum[end]);

	for (int i = 0; i < end; i++)
	{
		if (Convert::ToInt32(SplitNum[i]) >= N)
			return "False";
	}

	return "True";
}

void Main() 
{
	IPAddress ^IPadd;			// IP сервака
	TcpListener ^listener;		// для 'прослушивания' порта

	try
	{
		array<IPAddress^> ^localIP = Dns::GetHostAddresses(Dns::GetHostName());
		for each (IPAddress ^address in localIP)
		{
			if (address->AddressFamily == AddressFamily::InterNetwork)
			{
				IPadd = address;
				break;
			}
		}

		listener = gcnew TcpListener(IPadd, 8001);
		listener->Start();

		Console::WriteLine("The server is running at port 8001...");
		Console::WriteLine("The local End point is  :" + listener->LocalEndpoint);
	}
	catch (Exception ^e)
	{
		Console::WriteLine(e->Message);
		return;
	}	

	while (true)
	{
		try
		{
			Console::WriteLine("Waiting for a connection.....");
			TcpClient ^client = listener->AcceptTcpClient();		// ждем клиента
			Console::WriteLine("Connection accepted from " + client->Client->RemoteEndPoint);

			Stream ^stm = client->GetStream();

			BinaryReader ^reader = gcnew BinaryReader(stm);
			BinaryWriter ^writer = gcnew BinaryWriter(stm);

			String ^data = "";
			while (client->Connected)
			{
				Console::WriteLine("waiting for data\n");
				
				if (stm->CanRead)								// можем начать считывание из потока							
				{
					data = reader->ReadString();
					if (data != "")								// ждем когда в буфере появятся данные
					{
						Console::WriteLine("Received \n");
						Console::WriteLine(data);
						String ^str = Count(data);
						Console::WriteLine("result: " + str);
						writer->Write(str);	// вернули результат функции Count	
						Threading::Thread::Sleep(500);
					}
				}
			}
		}
		catch (Exception ^e)
		{
			Console::WriteLine(e->Message);
			Console::WriteLine("connection lost\n");
		}
	
	}
}

