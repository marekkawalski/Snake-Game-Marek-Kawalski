#include "Fruit.h"

void Fruit::initialize(unique_ptr<sf::RenderWindow>& window, unique_ptr<Game_Asset_Manager>& assets, string& file, int id)
{
	assets->Add_Texture(file, false);
	fruit.setTexture(assets->Get_My_texture(id));
}
void Fruit::setPosition(float x, float y)
{
	fruit.setPosition(x, y);
}
sf::FloatRect Fruit::get_bounds()
{
	return fruit.getGlobalBounds();
}
void Fruit::draw(unique_ptr<sf::RenderWindow>& window)
{
	window->draw(fruit);
}