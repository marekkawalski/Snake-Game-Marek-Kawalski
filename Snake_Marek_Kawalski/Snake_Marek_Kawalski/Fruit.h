#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Game_Asset_Manager.h"
#include "Game.h"
using namespace std;
/**Klasa zawiera atrybuty i metody do obslugi owocow oraz bomb pojawiajacych sie w grze*/
class Fruit 
{
	friend class Snake_Game_Board;
	friend class Snake;
	sf::Sprite fruit;
public:
	/**Konstruktor klasy owoc.*/
	Fruit(){}
	/**Metoda odpowiedzialna za inicjalizacje owoca, bomby.
	* Dodaje grafike owoca do wektora tekstur/spritow, a nastepnie ustawia sprite owoca na te grafike.
	* @param window inteligentny wskaznik na obiekt klasy przechowujacej okno programu. Obiekt window jest przekazany przez referencje. 
	* @param assets inteligentny wskaznik na obiekt klasy przechowujacej tekstury oraz fonty. Obiekt assets jest przekazany przez referencje.
	* @param file referencja na nazwe pliku, zawierajacego grafike owoca.
	* @param id id owoca w wektorze tekstur.
	* @return nic nie zwraca
	*/
	void initialize(unique_ptr<sf::RenderWindow>& window, unique_ptr<Game_Asset_Manager>& assets, string& file, int id);
	/**Metoda ustawiajaca pozycje owoca na ekranie
	* @param x pozycja obiektu na osi x (szerokosc okna)
	* @param y pozycja obiektu na osi y (wysokosc okna)
	* @return nic nie zwraca
	*/
	void setPosition(float x, float y);
	/**Metoda zwracajaca prostokat, w ktorego obrebie zawarty jest owoc.
	* @param brak parametrow
	* @return granice obiektu klasy owoc
	*/
	sf::FloatRect get_bounds();
	/**Metoda odpowiedzialna za rysowanie sprita na ekranie
	* @param window inteligentny wskaznik na obiekt klasy przechowujacej okno programu. Obiekt window jest przekazany przez referencje.
	* @return nic nie zwraca
	*/
	void draw(unique_ptr<sf::RenderWindow>& window);
	/**Destruktor klasy owoc.*/
	~Fruit() {}
};