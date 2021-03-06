#include "stdafx.h"

extern "C" DLL_PUBLIC bool API_Initialize(void) {
	// When Plugin gets loaded
	API::Server::PrintMessage(L"Initialized");
	return true;
}

extern "C" DLL_PUBLIC bool API_Close(void) {
	// When plugin gets unloaded
	API::Server::PrintMessage(L"Closed");
	return true;
}

extern "C" DLL_PUBLIC bool API_OnTick(void) {
	// Every server tick this gets called
	API::Server::PrintMessage(L"Tick");
	return true;
}

extern "C" DLL_PUBLIC bool API_OnPlayerConnecting(const std::string guid, const std::string playername)
{
	// When a player connects (still loading everything from the server)	
	API::Server::PrintMessage(L"Connecting");
	return true;
}

extern "C" DLL_PUBLIC bool API_OnPlayerConnected(int entity)
{
	// When the player is successfully connected (loaded in, but not spawned yet)
	API::Server::PrintMessage(L"Connected");
	return true;
}

/// <param name="reason">The reason the player disconnected,  0 = Left, 1 = Timeout, 2 = Kicked, 3 = Banned</param>
extern "C" DLL_PUBLIC void API_OnPlayerDisconnected(int entity, int reason)
{
	// When the player has disconnected the server
	API::Server::PrintMessage(L"Disconnected");
}

// When a entity enters a checkpoint (only players right now)
extern "C" DLL_PUBLIC void API_OnEntityEnterCheckpoint(int checkpoint, int entity)
{
	API::Server::PrintMessage(L"OnEntityEnterCheckpoint");
}

// When a entity exits a checkpoint (only players right now)
extern "C" DLL_PUBLIC void API_OnEntityExitCheckpoint(int checkpoint, int entity)
{
	API::Server::PrintMessage(L"OnEntityExitCheckpoint");
}

// When a player sends a command
extern "C" DLL_PUBLIC void API_OnPlayerCommand(const int entity, const std::string message)
{
	API::Server::PrintMessage(L"OnPlayerCommand");
}

// When a player sends a message
extern "C" DLL_PUBLIC void API_OnPlayerMessage(const int entity, const std::string message)
{
	API::Server::PrintMessage(L"OnPlayerMessage");
}

// When a CEF page has finished loading
extern "C" DLL_PUBLIC void API_OnCefFinishLoad(const int entity)
{
	API::Server::PrintMessage(L"OnCefFinishLoad");
}

// When a CEF page sends data
extern "C" DLL_PUBLIC void API_OnCefSendData(const int entity, const std::string data)
{
	API::Server::PrintMessage(L"API_OnCefSendData");
}