#pragma once
#include <iostream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;
/**Klasa, ktora przechowuje i zarzadza zasobami wykorzystywanymi w grze.*/
class Game_Asset_Manager
{
	vector<unique_ptr<sf::Font>>font;
	vector<unique_ptr<sf::Texture>>texture;
public:
	/**Konstruktor klasy Game_Asset_Manager.*/
	Game_Asset_Manager();
	/**Metoda, ktora tworzy obiekt klasy Font, ktory przechowuje czcionke i dodaje
	ja do wektora czcionek.
	* @param file stala referencja na plik, w ktorym znajduje sie czcionka.
	* @return nic*/
	void Add_Font(const string& file);
	/**Metoda, ktora tworzy obiekt klasy Texture, ktora przechowuje tekstury i dodaje
	ja do wektora tekstur.
	* @param file stala referencja na plik, w ktorym znajduje sie czcionka.
	* @param repeated czy tekstura ma sie powtarzac, jesli tak to wywolaj metode setRepeated.
	* @return nic */
	void Add_Texture(const string& file, bool repeated);
	/**Metoda, ktora znajduje teksture pod danym indeksem wektora i zwraca 
	stala referencje na wartosc spod tego indeksu.
	* @param index indeks wektora gdzie przechowywana jest tekstura.
	* @return stala referencja na teksture*/
	const sf::Texture &Get_My_texture(int index) const;
	/**Metoda, ktora znajduje czcionke pod danym indeksem wektora i zwraca
	stala referencje na wartosc spod tego indeksu.
	* @param index indeks wektora gdzie przechowywana jest czcionka.
	* @return stala referencja na czcionke.*/
	const sf::Font &Get_My_Font(int index) const;
	/**Destruktor klasy Game_Asset_Manager.*/
	~Game_Asset_Manager(){}
};

