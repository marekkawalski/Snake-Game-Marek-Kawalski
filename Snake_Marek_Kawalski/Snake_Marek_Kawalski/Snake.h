#pragma once
#include "Game_State.h"
#include "Game_Asset_Manager.h"
#include <memory>
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Game.h"
#include "Fruit.h"
#include "wall.h"
#include <list>
using namespace std;
/**Klasa zawierajaca metody obslugujace snaka oraz go tworzace.*/
class Snake
{
	friend class Bullet;
	int points_counter;
	string snake_file;
	list<sf::Sprite>body;
	list<sf::Sprite>::iterator pHead;
	list<sf::Sprite>::iterator pTail;
	list<sf::Sprite>::iterator p;
	list<sf::Sprite>::iterator Headd;
	list<sf::Sprite>::iterator Taill;
	sf::Vector2f direction;
	sf::Vector2f previous_direction;
	sf::Vector2f direction_up;
	sf::Vector2f direction_down;
	sf::Vector2f direction_left;
	sf::Vector2f direction_right;
	sf::Time how_much_time;
	bool shot = false;
public:
	/**Konstruktor klasy Snake. Wczytuje taksture snaka, ustawia kierunki jego poruszania, iteratory
	na pierwszy i ostatni element listy, w ktorej przechowywane sa segmenty snaka. Tutaj,
	takze ustawiana jest poczatkowa dlugosc weza.*/
	Snake();
	/**Ustawia poczatkowa pozycje weza na ekranie. Ponadto, kazdemu segmentowi snaka przypisywana
	jest taka sama tekstura.
	* @param snake_start_posx wspolrzedna startowa snaka na osi x
	* @param snake_start_posy wspolrzedna startowa snaka na osi y
	* @param window inteligentny wskaznik na obiekt klasy RenderWindow, przekazywany przez referencje
	* @param assets inteligentny wskaznik na obiekt klasy Game_Asset_Manager, przekazywany przez referencje
	* @return nic
	*/
	void initialize(float snake_start_posx, float snake_start_posy, unique_ptr<sf::RenderWindow>& window, unique_ptr<Game_Asset_Manager>& assets);
	/**Metoda, ktora wczytuje, ktore klawisze byly nacisniete i na tej podstawie ustawia kierunki,
	w ktorych porusza sie snake.
	* @param event zdarzenie
	* @return nic*/
	void snake_steering(sf::Event event);
	/**Metoda, ktora przemieszcza snaka po ekranie. Dzieje sie to poprzez przestawianie obiektu,
	na ktory wskazuje pTail na pozycje pHead plus kierunek poruszania w petli az do przestawienia calego
	ciala snaka na nowy kierunek poruszania.
	* @param brak
	* @return nic
	*/
	void move();
	/**Metoda, ktora rysuje wszystkie segmenty snaka na ekranie
	* @param window inteligentny wskaznik na obiekt klasy RenderWindow, przekazywany przez referencje
	* @return nic*/
	void draw(unique_ptr<sf::RenderWindow>& window);
	/**Metoda, ktora dodaje dodatkowy segment do ciala snaka. Jest on ustawiany na pozycje przed
	pozycja glowy weza. 
	* @param assets inteligentny wskaznik na obiekt klasy Game_Asset_Manager, przekazywany przez referencje
	* @return nic*/
	void grow(unique_ptr<Game_Asset_Manager>& assets);
	/**Metoda, ktora sprawdza czy glowa weza nie uderza w ktoras ze scian.
	* @param wallee inteligentny wskaznik na obiekt klasy my_Wall, przekazywany przez referencje.
	* @return true jesli snake uderza w sciane
	* @return false jesli snake nie uderza w sciane*/
	bool goingToBumpIntoWall(unique_ptr<my_Wall>&wallee);
	/**Metoda, ktora sprawdza czy glowa weza nie jest na pozycji, owoca.
	* @param fruit inteligentny wskaznik na obiekt klasy Fruit, przekazywany przez referencje.
	* @return true jesli snake wjezdza w owoc
	* @return false jesli snake nie wjezdza w owoc*/
	bool collision(unique_ptr<Fruit>&fruit);
	/**Metoda sprawdzajaca czy glowa snaka nie uderza, w ktorys z segmentow jego ciala.
	* @param brak
	* @return true jesli glowa uderza w jakis segment weza
	* @return false jesli glowa nie uderza w jakis segment weza
	*/
	bool hitting_itself();
	/**Metoda dodajaca punkty do ilosci punktow gracza
	* @param amount ilosc przyznawanych punktow
	* @return nic
	*/
	void admit_points(int amount);
	/**Metoda sprawdzajaca ile gracz zdobyl punktow
	* @param brak
	* @return ilosc punktow w danej rozgrywce
	*/
	int amount_of_points();
	/**Destruktor klasy Snake*/
	~Snake() {}
};
