#pragma once
#include <stack>
#include "Game_State.h"
#include <memory>
#include <deque>
using namespace std;
/**Klasa przechowujaca wszytskie stany gry w kontenerze deque oraz nimi zarzadzajaca.*/
class Game_State_manager
{
	deque <unique_ptr<Game_State >> deque_of_states;
	unique_ptr<Game_State>new_state;  //wskaznik na nowy stan gry
	bool add_state, remove, replace;
public:
	/**Konstruktor klasy Game_State_manager, ktory ustawia zmienne boolowe na falsz.*/
	Game_State_manager();
	/**Metoda, ktora przenosi inteligentny wskaznik przkezany jako parametr metody do zmiennej new_state
	oraz ustawia zmienna add_state na true.
	* @param adding_new_state inteligentny wskaznik na nowy stan gry
	* @param change_state parametr, ktory ustawia zmienna replace na true.
	* @return nic nie zwraca*/
	void add(unique_ptr<Game_State>adding_new_state, bool change_state = false);
	/**Metoda, ktora sprawdza czy kontener deque, w ktorym sa stany jest pusty.
	* @param brak
	* @return true jesli kontener jest pusty
	* @return false jesli kontener nie jest pusty*/
	bool is_empty();
	/**Metoda, ktora zmienia wartosc zmiennej remove na true.
	* @param brak
	* @return true*/
	bool remove_state();
	/**Najwazniejsza metoda klasy Game_State_manager. Dodaje lub usuwa nowe stany gry
	do deque stanow w zaleznosci od zmiennych boolowych add_state oraz remove.
	* @param brak
	* @return nic*/
	void changing_states();
	/**Metoda, ktora zwraca referencje na obiekt znajdujacy sie na przodzie kontenera deque, przechowujacego stan gry.
	Obiekt jest zarzadzany poprzez inteligentny wskaznik.
	* @param brak
	* @return referencja na obiekt (stan gry) zarzadzany poprzez unique_ptr*/
	unique_ptr<Game_State>& get_current_state();
	/**Destruktor klasy Game_State_manager.*/
	~Game_State_manager();
};

