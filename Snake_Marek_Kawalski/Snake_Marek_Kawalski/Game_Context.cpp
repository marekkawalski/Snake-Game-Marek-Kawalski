#include "Game_Context.h"

Game_Context::Game_Context()
{
	assets = make_unique<Game_Asset_Manager>();
	states = make_unique<Game_State_manager>();
	window = make_unique<sf::RenderWindow>();
	generator.seed(NULL);
}
