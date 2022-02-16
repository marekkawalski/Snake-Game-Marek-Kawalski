#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "Menu.h"
using namespace std;

/**Klasa stworzona do oblusgi przyciskow w grze.*/
class Button
{
    friend class End_of_game;
    friend class Menu;
    friend class About;
    friend class Game_Pause;
    sf::RectangleShape shape;
    sf::Color idle;
    sf::Color hover;
    sf::Color active;
    sf::Text text;
    bool is_button_pressed;
    sf::Font font;
public:
    /**Konstruktor klasy Button. Ustawia wiekszosc parametrow przycisku, m.in. jego kolory, wielkosc, font, napis na przycisku, jego pozycje na ekranie.
    * @param x pozycja przycisku na osi x
    * @param y pozycja przycisku na osi y
    * @param width szerokosc przycisku
    * @param height wysokosc przycisku
    * @param size wielkosc czcionki
    * @param font czcionka
    * @param text tekst na przycisku
    * @param fillColor kolor tekstu na przycisku
    * @param idleColor kolor wypelnienia przycisku w momencie, kiedy nie ma nad nim myszki
    * @param hoverColor kolor wypelnienia przycisku, kiedy jest nad nim myszka
    * @param activeColor kolor wypelnienia przycisku, kiedy zostanie nacisniety
    * @return nic
    */
    Button(float x, float y, float width, float height, int size, const sf::Font &font, string text, sf::Color fillColor, sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);
    /**Funkcja sprawdza czy myszka jest w obrebie przycisku.
    * @param window inteligentny wskaznik na okno programu, obiekt jest przekazany przez referencje.
    * @return true jesli myszka znajduje sie nad przyciskiem
    * @return false jesli myszki nie ma nad przyciskiem
    */
    bool mouse_over(unique_ptr<sf::RenderWindow>&window);
    /**Metoda zmieniajaca kolor przycisku w zaleznosci od polozenia myszki i faktu, czy przycisk zostal klikniety.
    Metoda zmienia rowniez wartosc atrybutu is_button_pressed na true, jesli przycisk zostal nacisniety.
    * @param window inteligentny wskaznik na okno programu, obiekt jest przekazany przez referencje.
    * @return nic*/
    void change_color(unique_ptr<sf::RenderWindow>& window);
    /**Metoda wyswietlajaca przycisk na ekranie
    * @param window inteligentny wskaznik na okno programu, obiekt jest przekazany przez referencje.*/
    void display(unique_ptr<sf::RenderWindow>& window);
    /**Destruktor klasy Button.*/
    ~Button(){}
};
