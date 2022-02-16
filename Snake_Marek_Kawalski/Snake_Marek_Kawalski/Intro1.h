#pragma once
#include <memory>
#include <iostream>
#include "Game_State.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Game_Context.h"
#include <string>
#include "Game.h"
using namespace std;
/**Klasa dziedziczaca po klasie Game_State. Jej zadaniem jest wyswietlenie tekstu poczatkowego, intra na ekranie.
Jest to pierwszy stan, tworzony w klasie Game.*/
class Intro1 : public Game_State
{
    shared_ptr<Game_Context>context;
    sf::Text text;
public:
    /**Konstruktor klasy Intro1. 
    * @param context1 inteligentny wskaznik na obiekt klasy Game_Context, przekazywany przez referencje.
    * @return nic 
    */
    Intro1(shared_ptr<Game_Context>& context1);
    /**Destruktor klasy Intro1*/
    ~Intro1(){}
    /**Metoda inicjalizujaca obiekt klasy Intro1. Dodaje czcionke do wektora czcionek, ustawia wielkosc liter, tresc
    tekstu, jego pozycje i pochodzenie na ekranie.
    * @param brak
    * @return nic*/
    virtual void initialize();
    /**Metoda przechwytujaca input z klawiatury. Po nacisnieciu dowolnego klawisza, oprocz ESC ktory konczy gre,
    tworzony jest nowy obiekt nastepnego stanu gry a obiekt klast Intro1 jest usuwany z wektora stanow.
    Z gry mozna takze wyjsc uzywajac srodkowego przycisku myszki.
    * @param brak
    * @return nic*/
    virtual void event_handler();
    /**Metoda nie jest wykorzystywana w tej klasie.*/
    virtual void update(sf::Time time);
    /**Metoda rysujaca tekst na ekranie
    * @param brak
    * @return nic*/
    virtual void draw();
};