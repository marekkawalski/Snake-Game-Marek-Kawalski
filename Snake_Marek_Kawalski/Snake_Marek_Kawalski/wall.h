#pragma once
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <array>
#include "Game_Asset_Manager.h"
using namespace std;
/**Klasa ustawiajaca sciane na ekranie.*/
class my_Wall 
{
	friend class Snake;
	friend class Snake_Game_Board;
	array<sf::Sprite, 4>walls;
	array<sf::FloatRect, 4>wallie;
public:
	/**Konstruktor klasy Wall*/
	my_Wall();
	/**Destruktor klasy Wall*/
	~my_Wall(){}
	/**Metoda inicjalizujaca sciane. Dodaje teksture sciany do wektora tekstur. Nastepnie, dla kazdej sciany w liscie
	ustawia teksture. Sciany sa ustawiane na swoich miejscach z wykorzystaniem metod setTextureRect oraz setRepeated.
	Pierwsza z nich okresla, ktore miejsce ma zostac zapelnione, a ta druga wypelnia je przeslana do wektora tekstur tekstura.
	* @param assets inteligentny wskaznik na obiekt klasy przechowujacej tekstury oraz fonty. Obiekt assets jest przekazany przez referencje.
	* @param file referencja na plik
	* @return nic nie zwraca
	*/
	void init(unique_ptr<Game_Asset_Manager>& assets, string& file);
	/**Metoda sprawdzajaca pozycje na ekranie kazdej ze scian, ktorych pozycje sa nastepnie zwracane w tablicy
	* @param brak
	* @return nic
	*/
	void set_bounds();
	/**Metoda wpisujaca do tablicy pozycje scian na ekranie.
	* @param brak
	* @return zwraca tablice pozycji scian na ekranie
	*/
	array<sf::FloatRect, 4> get_bounds();
	/**Metoda rysujaca sciany na ekranie
	* @param window inteligentny wskaznik na obiekt klasy przechowujacej okno programu. Obiekt window jest przekazany przez referencje.
	* @return nic
	*/
	void draw(unique_ptr<sf::RenderWindow>& window);
};

