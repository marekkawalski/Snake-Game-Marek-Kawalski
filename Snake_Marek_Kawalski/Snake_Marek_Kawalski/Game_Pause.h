#pragma once
#include "Game_State.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include "Button.h"
#include "Game_Context.h"
using namespace std;
/**Klasa pauzujaca gre. Dziedziczy ona po klasie Game_State*/
class Game_Pause :public Game_State
{
	shared_ptr<Game_Context>context;
	unique_ptr<Button>button_resume;
	unique_ptr<Button>button_exit;
	sf::Text text;
public:
	/**Konstruktor klasy Game_Pause.
	* @param context inteligentny wskaznik na obiekt klasy Game_Context, przekazany przez referencje.*/
	Game_Pause(shared_ptr<Game_Context>&context);
	/**Metoda, ktora tworzy obiekty klasy Button, button exit, button resume_game oraz 
	inicjalizuje tekst, ktory jest wyswietlany na ekranie pauzy.
	* @param brak
	* @return nic*/
	virtual void initialize();
	/**Metoda odpowiedzialna za input z klawiatury oraz myszki. Obsluguje zdarzenia po
	nacisnieciu przycisku oraz przycisku "P" albo spacji.
	* @param brak
	* @return nic*/
	virtual void event_handler();
	/**Metoda nie jest wykorzystywana w tej klasie.*/
	virtual void update(sf::Time time);
	/**Metoda, w ktorej na ekranie wyswietlane sa przyciski oraz rysowany jest tekst.
	Warto zaznaczyc, ze nie jest tutaj wykorzystywana metoda clear, ktora czysci ekran.
	Z tego powodu ekran wyglada identycznie jak w poprzednim stanie gry (Snake_Game_Board).*/
	virtual void draw();
	/**Destruktor klasy Game_Pause.*/
	~Game_Pause() {}
};

