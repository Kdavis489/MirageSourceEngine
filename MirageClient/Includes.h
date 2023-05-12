#ifndef INCLUDE_H
#define INCLUDE_H

//i/o libs
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include <ctime>
#include <vector>
//Network headers
#include "Network.h"
#include "Socket.h"
//#include "packetType.h"
//network constants
#ifdef _WIN32
#define WNI32_LEAN_AND_MEAN
#include <WinSock2.h>
#else
#include <sys\Socket.h>
#endif
typedef SOCKET SocketHandle;
const int M_MaxPacketSize = 8192;
//player includes
#include "Character.h"
#include "Inventory.h"


//GLFW/IMGUI lib's/includes


//graphics such goes here.
#endif