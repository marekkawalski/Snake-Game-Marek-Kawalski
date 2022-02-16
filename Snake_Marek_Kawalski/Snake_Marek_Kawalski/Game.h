/** @file */
#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Game_Context.h"
#include "Intro.h"
#include "Intro1.h"
#include <random>
/**Szerokosc okna*/
#define window_width 800
/**Wysokosc okna*/
#define window_height 480
/**Rozmiar sciany*/
#define wall_size 32
/**Dolna granica przedzialu czasu, w ktorym pojawiaja sie owoce*/
#define fruit_start_time 3
/**Gorna granica przedzialu czasu, w ktorym pojawiaja sie owoce*/
#define fruit_end_time 15
/**Minimalny indeks mapy, gdzie przehcowywane sa koncowe teksty.*/
#define start_text 0
/**Maksymalny indeks mapy, gdzie przehcowywane sa koncowe teksty.*/
#define ending_text 4
/**Minimalny mnoznik, ktory pozwala poruszac sie po zdjeciu zawierajacym owoce.*/
#define fruit_start 0
/**Maksymalny mnoznik, ktory pozwala poruszac sie po zdjeciu zawierajacym owoce.*/
#define fruit_end 7
/**Rozmiar owocu.*/
#define fruit_size 16
/**Minimalny indeks mapy, gdzie przehcowywane sa bomby.*/
#define bomb_start 1
/**Maksymalny indeks mapy, gdzie przehcowywane sa bomby.*/
#define bomb_end 12
/**Rozmiar pocisku.*/
#define bullet_size 13
/**Minimalny mnoznik, ktory pozwala poruszac sie po zdjeciu zawierajacym pociski.*/
#define bullet_start 0
/**Maksymalny mnoznik, ktory pozwala poruszac sie po zdjeciu zawierajacym pociski.*/
#define bullet_end 5
/**Poczatkowa dlugosc snaka.*/
#define snake_init_length 10
using namespace std;
/**Typ wyliczeniowy, dzieki ktoremu latwo mozna poruszac sie po indeksach wektora zawierajacego tekstury.*/
enum TexturetId
{
	snake_intro = 0,
	my_grass,
	my_apple,
	my_wall,
	snakie,
	my_diffrent_fruit,
	my_bomb,
	my_bullet
};
/**Typ wyliczeniowy, dzieki ktoremu latwo mozna poruszac sie po indeksach wektora zawierajacego fonty.*/
enum FontId
{
	Font = 0
};
/**Klasa zawierajaca glowna petle programu. Wywoluje wszytskie metody klasy Game_State dla konkretnych obiektow.*/
class Game
{
private:
	const sf::Time FPS = sf::seconds(1.f / 100.f);
	shared_ptr<Game_Context>context;
public:
	Game();
	/**Metoda zawierajaca glowna petle programu. Wywoluje wszytskie metody klasy Game_State dla konkretnych obiektow.
	* @param brak parametrow
	* @return nic nie zwraca
	*/
	void game();
	~Game() {}
};
