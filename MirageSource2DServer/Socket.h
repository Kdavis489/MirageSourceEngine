#ifndef SOCKET_H
#define SOOCKET_H

#include "socketHandle.h"
#include "msResult.h"
#include "IPVersion.h"
#include "sockOptions.h"
#include "IPEndpoint.h"

class Socket
{
public:
	Socket(IPVersion ipversion = IPVersion::IPv4,
		SocketHandle handle = INVALID_SOCKET);
	MSResult Create();
	MSResult Close();
	MSResult Bind(IPEndpoint endpoint);
	MSResult Listen(IPEndpoint endpoint, int backlog = 5);
	MSResult Accept(Socket& outSocket);
	MSResult Connect(IPEndpoint endpoint);
	MSResult Send(void* data, int numberOfBytes, int bytesSent);
	MSResult Recv(void* destination, int numberOfBytes, int& bytesReceived);
	SocketHandle GetHandle();
	IPVersion GetIPVersion();
private:
	MSResult SetSocketOption(SocketOption option, BOOL value);
	IPVersion ipversion = IPVersion::IPv4;
	SocketHandle handle = INVALID_SOCKET;
};

#endif