#ifndef PACKETTYPE_H
#define PACKETTYPE_H
#include <stdint.h>

enum class PacketType : uint16_t
{
	PT_Invalid,
	PT_ChatMessage,
	PT_IntegerArray,
};

#endif
