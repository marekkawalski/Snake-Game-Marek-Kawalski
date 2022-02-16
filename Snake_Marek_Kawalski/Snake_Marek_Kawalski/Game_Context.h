#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include "Game_Asset_Manager.h"
#include "Game_State_manager.h"
#include <random>
using namespace std;
/**Klasa przechowujaca inteligentne wskazniki na okno, stany gry oraz zasoby gry. W niej takze sa przechowywane
zmienne, ktore wykorzystywane sa przez rozne klasy. Dzieki klasie Game_Context kazda klasa ma dostep do tych samych
zasobow i tego samego okna. Ta klasa jest swojego rodzaju zapleczem pozostalych klas.*/
class Game_Context
{
	friend class Game;
	friend class Intro;
	friend class Intro1;
	friend class Menu;
	friend class Button;
	friend class Snake_Game_Board;
	friend class End_of_game;
	friend class About;
	friend class Game_Pause;
	unique_ptr<Game_Asset_Manager>assets;
	unique_ptr<Game_State_manager>states;
	unique_ptr<sf::RenderWindow>window;
	default_random_engine generator;
	int points_quantity = 0;
	sf::SoundBuffer crash_buffer;
	sf::Sound crash_sound;
	sf::SoundBuffer bomb_buffer;
	sf::Sound bomb_sound;
	sf::SoundBuffer death_buffer;
	sf::Sound death_sound;
	sf::SoundBuffer shoot_buffer;
	sf::Sound shoot_sound;
	bool move_snake = true;
public:
	/**Konstruktor klasy Game_Context. W nim tworzone sa obiekty klas Game_Asset_Manager, Game_State_Manager oraz
	RenderWindow. Ponadto, konstruktor klasy Game_Context wywoluje metode seed na generatorze liczb pseudolosowych, co
	zapewnia ich losowosc przy kazdym wywolaniu programu.*/
	Game_Context();
	/**Destruktor klasy Game_Context.*/
	~Game_Context() {}
};
