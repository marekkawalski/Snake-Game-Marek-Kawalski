#pragma once
#include <memory>
#include <iostream>
#include "Game_State.h"
#include <SFML/Graphics.hpp>
#include "Game_Context.h"
using namespace std;
/**Klasa bedaca stanem gry, dziedziczaca po klasie Game_State. Wyswietla ona obrazek Snaka. Jest to druga czesc Intra.*/
class Intro : public Game_State
{
    shared_ptr<Game_Context>context;
    sf::Sprite picture;
public:
    /**Konstruktor klasy Intro.
    * @param context inteligentny wskaznik na obiekt klasy Game_Context, przekazywany przez referencje.*/
    Intro(shared_ptr<Game_Context>& context);
    /**Metoda dodaje grafike snaka do wektora zasobow. Ustawia takze Sprita picture na te wlasnie grafike.
    * @param brak
    * @return nic*/
    virtual void initialize();
    /**Metoda obslugujaca input z klawiatury. Czeka na nacisniecie dowolnego przycisku na klawiaturze aby
    zmienic stan gry na nastepny.
    * @param brak
    * @return nic*/
    virtual void event_handler();
    /**Metoda nie jest wykorzystywana w tej klasie.*/
    virtual void update(sf::Time time);
    /**Metoda rysujaca grafike snaka na ekranie. Ustawia rowniez skale wielkosci grafiki.
    * @param brak
    * @return nic*/
    virtual void draw();
    /**Destruktor klasy Intro.*/
    ~Intro(){}
};

