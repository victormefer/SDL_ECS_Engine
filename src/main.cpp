#ifdef __APPLE__
	# include <lua5.2/lua.hpp>
#endif

#include <iostream>

#include "../include/Game.hpp"
#include "../include/Resources.hpp"
#include "../include/MainMenuState.hpp"

#define		CONFIG_FILE	"../config.txt"

int Resources::WINDOW_WIDTH 		= 0;
int Resources::WINDOW_HEIGHT 		= 0;
int Resources::TILE_WIDTH 			= 0;
int Resources::TILE_HEIGHT 			= 0;
int Resources::GRAVITY 				= 0; // pixels per second
float Resources::PLAYER_WALK_SPEED 	= 0; // pixels per second
float Resources::PLAYER_JUMP_SPEED 	= 0; // pixels per second


int main(int argc, char *argv[])
{
	Resources::Read(CONFIG_FILE);

	Game game("Umbra", Resources::WINDOW_WIDTH,Resources::WINDOW_HEIGHT);
	game.push(new MainMenuState());
	game.run();

	return 0;
}
