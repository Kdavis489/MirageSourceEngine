#ifndef NETWORK_H
#define NETWORK_H

#define WIN32_LEAN_AND_MEAN

#include <WinSock2.h>

struct Network
{
public:
	static bool Initialize();
	static void Shutdown();

};
#endif
