#pragma once
#include "Game_State.h"
#include "Game_Context.h"
#include "Button.h"
#include "Game.h"
#include "Menu.h"
#include <memory>
#include <SFML/Graphics.hpp>
using namespace std;
/**Klasa wyswoetlajaca informacje o tym jak grac. Dziedziczy z klasy Game_State*/
class About: public Game_State
{
    shared_ptr<Game_Context>context;
    unique_ptr<Button>button_back;
    sf::Text text;
    string some_text;
    sf::Text more_text;
    string m_text_string;
public:
    /**Konstruktor klasy About.
    * @param context inteligentny wskaünik typu shared_ptr, wskazujacy na obiekt klasy Game_Context. Obiekt przekazywany jest przez referencje.
    */
    About(shared_ptr<Game_Context>& context);
    /**Inicjalizacja tekstu. Ustawienie tekstu, czcionki oraz ich pozycji na ekranie. Tworzony jest tutaj rowniez obiekt klasy Button.*/
    virtual void initialize();
    /**Metoda obsluguje zdarzenia zwiazane z najechaniem badz kliknieciem na przycisk.*/
    virtual void event_handler();
    /**Metoda nie jest wykorzystywana w tej klasie. Musiala zostac zakryta, poniewaz jest to metoda czysto wirtualna klasy bazowej klasy About.*/
    virtual void update(sf::Time time);
    /**Metoda sluzaca do narysowania tekstu oraz przycisku na ekranie.*/
    virtual void draw();
    /**Destruktor klasy About.*/
    ~About();
};

