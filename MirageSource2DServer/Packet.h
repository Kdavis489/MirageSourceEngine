#ifndef PACKET_H
#define PAKCET_H
#define WIN32_LEAN_AND_MEAN
#include "Includes.h"
#include "PacketException.h"
#include "packetType.h"

class Packet
{
public:
	Packet(PacketType packetType = PacketType::PT_Invalid);
	PacketType GetPacketType();
	void AssignPacketType(PacketType packetType);

	void Clear();
	void Append(const void* data, uint32_t size);

	Packet& operator << (uint32_t data);
	Packet& operator >> (uint32_t& data);

	Packet& operator << (const std::string& data);
	Packet& operator >> (std::string& data);

	uint32_t extractionOffset = 0;
	std::vector<char> buffer;
};
#endif