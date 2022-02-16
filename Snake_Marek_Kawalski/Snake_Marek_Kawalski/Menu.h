#pragma once
#include "Game_State.h"
#include "Game_Context.h"
#include "Snake_Game_Board.h"
#include "Button.h"
#include "Game.h"
#include <memory>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "About.h"
using namespace std;
/**Klasa, ktorej zadaniem jest utworzenie, obsluga oraz wyswietlenie menu gry.
Dziedziczy publicznie po klasie Game_State.*/
class Menu : public Game_State
{
    shared_ptr<Game_Context>context;
    sf::Text text;
    sf::Text texttt;
    sf::Text texttt2;
    unique_ptr<Button>button_play;
    unique_ptr<Button>button_how_to;
    unique_ptr<Button>button_exit;
public:
    /**Konstruktor klasy Menu. Przypisuje wskaznik do klasy Game_Context.
    * @param context inteligentny wskaznik na obiekt klasy Game_Context, przekazywany przez referencje.*/
    Menu(shared_ptr<Game_Context>& context);
    /**Metoda, ktora tworzy obiekty klasy Button oraz ustawi teksty na ekranie.
    * @param brak
    * @return nic
    */
    virtual void initialize();
    /**Metoda, ktora obsluguje input myszki. Sa trzy mozliwe sytuacje: myszka jest
    nad przyciskiem, przycisk zostal klikniety lub myszki nie ma nad przyciskiem.
    * @param brak
    * @return nic*/
    virtual void event_handler();
    /**Metoda nie jest wykorzystywana w tej klasie.*/
    virtual void update(sf::Time time);
    /**Metoda, ktora rysuje przyciski oraz tekst na ekranie.
    * @param brak
    * @return nic*/
    virtual void draw();
    /**Destruktor klasy Menu.*/
    ~Menu(){}
};

