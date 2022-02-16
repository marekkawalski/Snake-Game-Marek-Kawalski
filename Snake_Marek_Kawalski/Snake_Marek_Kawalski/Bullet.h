#pragma once
#include "Game_Asset_Manager.h"
#include <memory>
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Game.h"
#include "Fruit.h"
#include "wall.h"
#include <vector>
#include <algorithm>
#include "Snake.h"
using namespace std;
/**Klasa zawierajaca metody i atrybuty do tworzenia kul, ktorymi strzela snake.*/
class Bullet
{
public:
	sf::Sprite bullet;
	sf::Vector2f current_velocity;
	string bullet_file;
	/**Konstruktor klasy Bullet. Ustawia obecna predkosc kuli na 0,0.*/
	Bullet();
	/**Metoda sluzaca do inicjalizacji tekstur.
	* @param assets inteligentny wskaznik na obiekt klasy przechowujacej tekstury oraz fonty. Obiekt assets jest przekazany przez referencje.
	* @param window inteligentny wskaznik na obiekt klasy przechowujacej okno programu. Obiekt window jest przekazany przez referencje.
	* @return nic nie zwraca
	*/
	void init(unique_ptr<Game_Asset_Manager>& assets, unique_ptr<sf::RenderWindow>& window);
	/**Ustawienie pozycji pociskow strzelanych przez snaka oraz ustawienie ich predkosci.
	* @param snake inteligentny wskaznik na obiekt klasy Snake, przekazywany przez referencje.
	* @param speed predkosc pocisku
	*/
	void bullet_set_position(unique_ptr<Snake>& snake, double speed);
	/**Metoda sprawdzajaca czy pocisk zderza sie z owocem.
	* @param fruit inteligentny wskaznik na obiekt klasy Fruit, przekazywany przez referencje.
	* @return true jesli nastepuje zderzenie
	* @return false jesli zderzenie nie nastepuje
	*/
	bool collision(unique_ptr<Fruit>& fruit);
	/**Metoda sprawdzajaca czy snake nie strzela sam w siebie.
	* @param fruit inteligentny wskaznik na obiekt klasy Fruit, przekazywany przez referencje.
	* @return true jesli nastepuje strzelenie samego siebie
	* @return false jesli snake nie strzela sam do siebie
	*/
	bool shooting_itself(unique_ptr<Snake>& snake);
};
