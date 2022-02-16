#pragma once
#include <iostream>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics.hpp>
/**Klasa abstrakcyjna zawierajaca metody czysto wirtualne, z ktorej dziedzicza wszystkie stany gry.
*/
class Game_State
{
public:
	/**Metoda czysto wirtualna. Zostanie zakryta przez metody klas pochodnych. W tej klasie nastepuje
	* inicjalizacja danych, tekstur, fontow, obiektow i itp.
	* @return nic nie zwraca
	*/
	virtual void initialize()=0;
	/**Metoda czysto wirtualna. W niej odbywa sie sprawdzanie inputu z klawiatury oraz myszki.
	*/
	virtual void event_handler()=0;
	/**Metoda czysto wirtualna. Sluzy do aktualizowania zdarzen, danych, obiektow po wykonaniu jakiegos zdarzenia
	* ,np. po nacisnieciu spacji, Snake zaczyna strzelac. Samo sprawdzenie czy spacja byla nacisnieta, odbywa sie
	* w metodzie initialize().
	* @see {initialize}
	* @param time czas po ktorym ma nastapic aktualizacja jakiegos parametru.
	* @return nic nie zwraca
	*/
	virtual void update(sf::Time time)=0;
	/**Metoda czysto wirtualna. Jej zadaniem jest narysowanie sprajtow, tekstur oraz tekstu na ekranie.
	* @return nic nie zwraca
	*/
	virtual void draw()=0;
	/**Metoda, ktora sprawdza czy jakis klawisz zostal nacisniety.
	* @return true jesli jakis klawisz byl wcisniety
	* @return false jesli zaden klawisz nie byl wcisniety
	*/
	bool is_any_key_pressed();
	/**Wirtualny destruktor klasy abstrakcyjnej.
	*/
	virtual ~Game_State() {}
};

