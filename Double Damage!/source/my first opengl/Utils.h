#pragma once
#include <iostream>
#include "ShaderLoader.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"


#define SRCWIDTH 800
#define SRCHEIGHT 600

struct PositionStruct
{
	float x;
	float y;
	float z;
};

struct ColorStruct
{
	float r;
	float g;
	float b;
};

struct TexCoordStruct
{
	float x;
	float y;
};

class Utils
{
public:
	Utils();
	~Utils();
	PositionStruct CreatePositionStruct();
	void CreateTexCoordStruct();
	void CreateVertexFormatStruct();
	void CreateIndexFormatStruct();
	void SetQuadVertices();
	void SetResolution();
};

#pragma once

#if !defined(__UTILS_H__)
#define __UTILS_H__

// Library Includes
#include <WS2tcpip.h>
#include <string>
#include <strstream>

// Local Includes

// Types

// Constants


// Prototypes

#define VALIDATE(a) if (!a) return (false)

namespace {
	std::string ToString(sockaddr_in _sockAddress)
	{
		//INET_ADDRSTRLEN - maximum length for IPv4 addresses
		char _pcAddress[INET_ADDRSTRLEN];
		inet_ntop(AF_INET, &_sockAddress.sin_addr, _pcAddress, INET_ADDRSTRLEN);

		std::string _strAddress = _pcAddress;
		std::string _strPort = std::to_string(ntohs(_sockAddress.sin_port));
		std::string _strAddressPort = _strAddress + ':' + _strPort;

		return _strAddressPort;
	}
}

template<typename T>
std::string ToString(const T& _value)
{
	std::strstream theStream;
	theStream << _value << std::ends;
	return (theStream.str());
}


#endif    // __UTILS_H__

