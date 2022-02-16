#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <memory>
#include "Game_State.h"
#include "Button.h"
#include "Game_Context.h"
#include <map>
#include "Snake.h"
#include <fstream>
#include "Menu.h"
using namespace std;
/**Klasa, ktora jest koncowym stanem gry, zapisuje wynik rozgrywki do pliki, wyswietla wynik i umozliwia ponowne rozpoczecie rozgrywki.
Dziedziczy ona po klasie Game_State.*/
class End_of_game : public Game_State
{
	shared_ptr<Game_Context>context;
	sf::Text text;
	sf::Text endText;
	sf::Text max_score_text;
	unique_ptr<Button>button_play_again;
	unique_ptr<Button>button_exit;
	unique_ptr<Button>button_menu;
	map<int, string>map_of_texts_1;
	map<int, string>map_of_texts_2;
	map<int, string>map_of_texts_3;
	int max_point = 0;
	int random_number;
public:
	/**Konstruktor klasy End_of_game.
	* @param context inteligentny wskaznik na obiekt klasy Game_Context, przekazywany przez referencje.*/
	End_of_game(shared_ptr<Game_Context>& context);
	/**Metoda inicjalizujaca stan End_of_game. Tworzy obiekt klasy Button, wyswietla ilosc punktow na ekranie,
	wczytuje maksymalna ilosc punktow z pliku i jesli liczba punktow z obecnej rozgrywki przewyzsza te poprzednia
	to jest ona zapisywana do tego pliku. Ponadto, w tej metodzie jest inicjalizowana mapa tekstow, ktore sa wyswietlane w zaleznosci od
	ilosci punktow.
	* @param brak
	* @return nic*/
	virtual void initialize();
	/**Metoda sluzaca do obslugi przyciskow w zaleznosci od inputu z myszki.
	* @param brak
	* @return nic*/
	virtual void event_handler();
	/**Metoda nie jest wykorzystywana w tej klasie.*/
	virtual void update(sf::Time time);
	/**Metoda, ktora wybiera tekst, ktory zostanie wyswietlony na ekranie. Robi to biorac pod uwage
	liczbe punktow uzyskanych przez gracza.
	* @param brak
	* @return nic*/
	void set_points();
	/**Metoda, ktora rysuje teksty jak i przyciski na ekranie.
	* @param brak
	* @return nic*/
	virtual void draw();
	/**Metoda, ktora wczytuje maksymalna ilosc punktow z pliku tekstowego.
	* @param filename nazwa pliku tekstowego, w ktorym zapisywany jest maksymalny wynik gracza.
	* @return maksymalna ilosc punktow gracza*/
	int read_from_file(string filename);
	/**Metoda, ktora zapisuje nowa maksymalna ilosc punktow do pliku.
	* @param filename nazwa pliku tekstowego, w ktorym zapisywany jest maksymalny wynik gracza.
	* @return nic
	*/
	void save_to_file(string filename);
	/**Destruktor klasy End_of_game*/
	~End_of_game() {}
};
