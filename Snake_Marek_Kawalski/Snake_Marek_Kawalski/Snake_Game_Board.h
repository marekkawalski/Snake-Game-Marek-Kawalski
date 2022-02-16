#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <memory>
#include <array>
#include <vector>
#include "Game_State.h"
#include "Game_Context.h"
#include "Game.h"
#include "Fruit.h"
#include "Snake.h"
#include "wall.h"
#include <random>
#include "End_of_game.h"
#include <map>
#include "Bullet.h"
#include "Game_Pause.h"
using namespace std;
/**Najwazniejsza klasa, zawierajaca plansze gry oraz tworzaca wiekszosc obiektow wystepujacych w grze.
W tej klasie odbywa sie wlasciwa gra. Dziedziczy po klasie Game_State.*/
class Snake_Game_Board :public Game_State
{
	weak_ptr<Game_Context>weakPtr;
	shared_ptr<Game_Context>context;
	unique_ptr<Fruit>apple;
	unique_ptr<Fruit>diffrent_fruit;
	unique_ptr<Fruit>bomb;
	unique_ptr<Snake>snake;
	unique_ptr<my_Wall>wallee;
	sf::Sprite grass;
	string file;
	string fire_wall;
	string diffrent_fruit_file;
	string bomb_file;
	float snake_start_posx;
	float snake_start_posy;
	sf::Time how_much_time;
	sf::Time how_much_time2;
	sf::Time how_much_time3;
	sf::Time time2;
	sf::Time time3;
	int expectancy_time = 3;
	int expectancy_time2 = 3;
	sf::Vector2f position_on_screen;
	unique_ptr<uniform_int_distribution<int>>distributionx;
	unique_ptr<uniform_int_distribution<int>>distributiony;
	unique_ptr<uniform_int_distribution<int>>bomb_distributionx;
	unique_ptr<uniform_int_distribution<int>>bomb_distributiony;
	unique_ptr<uniform_int_distribution<int>>time_dist;
	unique_ptr<uniform_int_distribution<int>>fruitx;
	unique_ptr<uniform_int_distribution<int>>fruity;
	unique_ptr<uniform_int_distribution<int>>bombx;
	unique_ptr<uniform_int_distribution<int>>bulletx;
	map<int, sf::Texture>bombs_map;
	sf::SoundBuffer eat_buffer;
	sf::Sound eat_sound;
	double speed;
	sf::Text text;
	bool speed_set = false;
	bool space_pressed = false;
	Bullet bullet;
	vector<Bullet>bullets;
	sf::SoundBuffer disappear_buffer;
	sf::Sound disappear_sound;
public:
	/**Konstruktor klasy Snake_Game_Board. Przypisuje nazwy plikow do odpowienich atrybutow,
	nadaje snakowi pozycje startowa oraz ustawia kursor myszy na niewidoczny.
	* @param context inteligentny wskaznik na obiekt klasy Game_Context, przekazywany przez referencje.*/
	Snake_Game_Board(shared_ptr<Game_Context>& context);
	/**Metoda inicjalizujaca wiele obiektow wystepujacych w tym stanie gry. Inicjalizuje m. in.
	snaka, sciane, jablko, owoce, bomby, rozklady losowe, pociski oraz muzyke.
	* @param brak
	* @return nic*/
	virtual void initialize();
	/**Metoda, ktore obsluguje prawie caly input z klawiatury jaki jest w grze. Wywoluje ona metody innych
	klas, ktore zostaly zaprogramowane do obslugi zdarzen klawiatury.
	* @param brak
	* @return nic
	*/
	virtual void event_handler();
	/**Metoda, ktora wywoluje wszytskie metody zwiazane z poruszaniem, kolizjami oraz strzelaniem.
	Tutaj takze wywolane sa metody losujace przedzialy czasowe oraz miejsca pojawiania sie owocow
	oraz bomb.
	* @param time czas, po ktorym ma zostac zaaktualizowana jakas czesc intrukcji znajdujacych sie
	w tej metodzie.
	*/
	virtual void update(sf::Time time);
	/**Metoda rysujaca, badz wywolujaca metody rysujace, wyswietlajace obiekty na planszy gry
	* @param brak
	* @return nic
	*/
	virtual void draw();
	/**Metoda, ktora losuje randomowe pozycje obiektow na ekranie.
	* @param dysx rozklad zmiennej losowej x (polozenia obiektu na osi x)
	* @param dysy rozklad zmiennej losowej y (polozenia obiektu na osi y)
	* @return wektor intow, zawierajacy wylosowane pozycje na ekranie.
	*/
	sf::Vector2i set_random_position(uniform_int_distribution<int>dysx, uniform_int_distribution<int>dysy);
	/**Metoda losujaca randomowe pozycje dla owocow z zadanego przedzialu.
	* @param brak
	* @return wektor intow pozycji na ekranie dla owocow
	*/
	sf::Vector2i set_random_fruit();
	/**Metoda losujaca losowe liczby z zadanaego przedzialu
	* @param dys rozklad losowy
	* @return losowa liczba calkowita
	*/
	int set_random_number(uniform_int_distribution<int>dys);
	/**Metoda wywolywana w momencie gdy snake zje jablko. Odtwarza dzwiek zjedzenia jablka,
	przyznaje punkty, losuje nowa pozycje dla jablka
	* @param brak
	* @return nic
	*/
	void apple_collision();
	/**Metoda wywolywana w momencie gdy snake zje owoc, ktory nie jest obiektem "apple". Odtwarza dzwiek zjedzenia owocu,
	przyznaje punkty, losuje nowa pozycje dla owocu.
	* @param brak
	* @return nic
	*/
	void diffrent_fruit_collision();
	/**Metoda wywolywana w momencie gdy snake wjedzie w bombe. Odtwarza dzwiek wybuchu, konczy gre.
	* @param brak
	* @return nic
	*/
	void bomb_collision();
	/**Metoda wywolywana w momencie gdy snake wjedzie lub strzeli sam w siebie. Odtwarza dzwiek umierania, konczy gre.
	 * @param brak
	 * @return nic
	 */
	void snake_collision();
	/**Metoda wywolywana w momencie gdy snake wjedzie w sciane. Odtwarza dzwiek umierania, konczy gre.
	 * @param brak
	 * @return nic
	 */
	void wall_collision();
	/**Destruktor klasy Snake_Game_Board*/
	~Snake_Game_Board();
};
