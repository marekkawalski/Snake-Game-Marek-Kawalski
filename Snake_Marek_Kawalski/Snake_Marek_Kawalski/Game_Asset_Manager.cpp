#include "Game_Asset_Manager.h"

Game_Asset_Manager::Game_Asset_Manager() {}
void Game_Asset_Manager::Add_Font(const string& file)
{
	auto fonteee = make_unique<sf::Font>();
	if (fonteee->loadFromFile(file))
	{
		font.push_back(move(fonteee));
	}
	else
	{
		cout << "There is a problem with a font file" << endl;
	}
}
void Game_Asset_Manager::Add_Texture(const string& file, bool repeated = false)
{
	auto textureee = make_unique<sf::Texture>();
	if (textureee->loadFromFile(file))
	{
		textureee->setRepeated(repeated);
		texture.push_back(move(textureee));
	}
	else
	{
		cout << "There is a problem with a texture file" << endl;
	}
}
const sf::Texture& ::Game_Asset_Manager::Get_My_texture(int index) const
{
	int i = 0;
	while ((i < texture.size()) and i != index)
	{
		i++;
	}
	if (i == index)
	{
		return *(texture.at(index).get());
	}
}
const sf::Font& ::Game_Asset_Manager::Get_My_Font(int index) const
{
	bool found = false;
	int i = 0;
	while ((i < font.size()) and i != index)
	{
		i++;
	}
	if (i == index)
	{
		found = true;
		return *(font.at(index).get());
	}
	if (found == false)
	{
		cout << "Nie ma czcionki" << endl;
	}
}