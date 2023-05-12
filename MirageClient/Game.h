#ifndef GAME_H
#define GAME_H

#include "Includes.h"

struct Game
{
public:
	//Game(const char* title, const int WINDOW_WIDTH, const int WINDOW_HEIGHT, const int GL_VERSION_MAJOR, GL_VERSION_MINOR, bool resizable);
	Game();
	virtual ~Game();

	//operators

	//functions
	void mainMenu();
	void initGame();
	void createCharacter();
	void loadCharacter();
	void saveCharacter();
	void characterMenu();
	void selectCharacter();
	int running;
	//accessor
	inline bool getPlaying() const { return this->playing; }

private:
	//constants
	int choice;
	bool playing;

	//berkley sockets 
	Network network;
	SocketHandle socketHandle;
	IPVersion ipversion;
	std::string serverIp;
	int port;
	bool isConnected = false;
	Socket socket;

	//character assets
	int activeCharacter;
	std::vector<Character> characters;
	std::string filename;

	//item assets
	char nameBuf[256];
	char descBuf[256];
	char effectBuff[256];

	//constants
	const int M_MaxPacketSize = 8192;
	/*const int WINDOW_WIDTH;
	* const int WINDOW_HEIGHT;
	* int framebufferWidth;
	* int framebufferHeight;
	* const int GL_VERSION_MAJOR;
	* const int GL_VERSION_MINOR;
	*
	*/
	//private operators
	/*void initGLGW();
	* void initWindow(const char * title, bool resizeable);
	* initGlad();
	* initUI*/
	//private functions
};
#endif