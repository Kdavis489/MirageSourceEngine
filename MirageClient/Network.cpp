#include "Network.h"
#include <iostream>

bool Network::Initialize()
{
    WSADATA wsadata;
    int result = WSAStartup(MAKEWORD(2, 2), &wsadata);
    if (result != 0)
    {
        std::cerr << "failed to start up the winsock API." << std::endl;
        return false;
    }
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wVersion) != 2)
    {
        std::cerr << "could not find a usable version of the winsock api dll." << std::endl;
        return false;
    }
    return true;
}

void Network::Shutdown()
{
    WSACleanup();
}