#include "Socket.h"
#include <assert.h>
#include <iostream>

Socket::Socket(IPVersion ipversion, SocketHandle handle)
    :ipversion(ipversion), handle(handle)
{
    assert(ipversion == IPVersion::IPv4);
}

MSResult Socket::Create()
{
    assert(ipversion == IPVersion::IPv4);
    if (handle != INVALID_SOCKET)
    {
        return MSResult::M_NYI;
    }

    handle = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  //attempt to create socket
    if (handle == INVALID_SOCKET)
    {
        int error = WSAGetLastError();
        return MSResult::M_NYI;
    }

    if (SetSocketOption(SocketOption::TCP_NoDelay, TRUE) != MSResult::M_Success)
    {
        return MSResult::M_NYI;
    }

    return MSResult::M_Success;
}

MSResult Socket::Close()
{
    if (handle == INVALID_SOCKET)
    {
        return MSResult::M_NYI;
    }
    int result = closesocket(handle);
    if (result != 0)
    {
        int error = WSAGetLastError();
        return MSResult::M_NYI;
    }

    handle = INVALID_SOCKET;
    return MSResult::M_Success;
}

MSResult Socket::Bind(IPEndpoint endpoint)
{
    sockaddr_in addr = endpoint.GetSockadrIPv4();
    int result = bind(handle, (sockaddr*)(&addr), sizeof(sockaddr_in));
    if (result != 0) //if error occured
    {
        int error = WSAGetLastError();
        return MSResult::M_NYI;
    }

    return MSResult::M_Success;
}

MSResult Socket::Listen(IPEndpoint endpoint, int backlog)
{
    if (Bind(endpoint) != MSResult::M_Success)
    {
        return MSResult::M_NYI;
    }

    int result = listen(handle, backlog);
    if (result != 0) //if error occurred
    {
        int error = WSAGetLastError();
        return MSResult::M_NYI;
    }
    return MSResult::M_Success;
}

MSResult Socket::Accept(Socket& outSocket)
{
    sockaddr_in addr = {}; //zero address
    int len = sizeof(sockaddr_in); //size of IPv4 address

    SocketHandle acceptedConnectionHandle = accept(handle, (sockaddr*)(&addr), &len);
    if (acceptedConnectionHandle == INVALID_SOCKET)
    {
        int error = WSAGetLastError();
        return MSResult::M_NYI;
    }

    IPEndpoint newConnection((sockaddr*)&addr);
    std::cout << "New connection accepted!" << std::endl;
    newConnection.Print();

    outSocket = Socket(IPVersion::IPv4, acceptedConnectionHandle);

    return MSResult::M_Success;
}

MSResult Socket::Connect(IPEndpoint endpoint)
{
    sockaddr_in addr = endpoint.GetSockadrIPv4();
     int result = connect(handle, (sockaddr*)(&addr), sizeof(sockaddr_in));
    if (result != 0)
    {
        int error = WSAGetLastError();
        return MSResult::M_NYI;
    }
    return MSResult::M_Success;
}

MSResult Socket::Send(void* data, int numberOfBytes, int bytesSent)
{
    bytesSent = send(handle, (const char*)data, numberOfBytes, NULL);
    if (bytesSent == SOCKET_ERROR)
    {
        int error = WSAGetLastError();
        return MSResult::M_NYI;
    }

    return MSResult::M_Success;
}

MSResult Socket::Recv(void* destination, int numberOfBytes, int& bytesReceived)
{
    bytesReceived = recv(handle, (char*)destination, numberOfBytes, NULL);
    if (bytesReceived == 0)
    {
        return MSResult::M_NYI;
    }
    if (bytesReceived == SOCKET_ERROR)
    {
        int error = WSAGetLastError();
        return MSResult::M_NYI;
    }

    return MSResult::M_Success;
}

SocketHandle Socket::GetHandle()
{
    return handle;
}

IPVersion Socket::GetIPVersion()
{
    return ipversion;
}

MSResult Socket::SetSocketOption(SocketOption option, BOOL value)
{
    int result = 0;
    switch (option)
    {
    case SocketOption::TCP_NoDelay:
        result = setsockopt(handle, IPPROTO_TCP, TCP_NODELAY, (const char*)&value, sizeof(value));
        break;
    default:
        return MSResult::M_NYI;
    }

    if (result != 0)// If an error occurs
    {
        int error = WSAGetLastError();
        return MSResult::M_NYI;
    }
    return MSResult::M_Success;
}