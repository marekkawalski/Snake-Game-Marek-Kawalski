#include "Snake.h"

Snake::Snake()
{
	snake_file = "Textures/snakee.png";
	body=(list<sf::Sprite>(snake_init_length));
	pHead = --body.end();
	pTail = body.begin();
	direction = { 0.f, 16.f };
	direction_up = { 0.f, -16.f };
	direction_down = { 0.f, 16.f };
	direction_left = { -16.f, 0.f };
	direction_right = { 16.f, 0.f };
	points_counter = 0;
	previous_direction = direction_down;
}
void Snake::initialize(float snake_start_posx, float snake_start_posy, unique_ptr<sf::RenderWindow>& window, unique_ptr<Game_Asset_Manager>& assets)
{
	assets->Add_Texture(snake_file, false);
	for (auto &i : body)
	{
		i.setTexture(assets->Get_My_texture(snakie));
		i.setPosition(snake_start_posx, snake_start_posy);
		snake_start_posx += 17.f;
	}
}
void Snake::snake_steering(sf::Event event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::W: case sf::Keyboard::Up:
		if (previous_direction != direction_down)
		{
			direction = direction_up;
			previous_direction = direction_up;
		}
		break;
	case sf::Keyboard::S: case::sf::Keyboard::Down:
		if (previous_direction != direction_up)
		{
			direction = direction_down;
			previous_direction = direction_down;
		}
		break;
	case sf::Keyboard::A: case sf::Keyboard::Left:
		if (previous_direction != direction_right)
		{
			direction = direction_left;
			previous_direction = direction_left;
		}
		break;
	case sf::Keyboard::D: case sf::Keyboard::Right:
		if (previous_direction != direction_left)
		{
			direction = direction_right;
			previous_direction = direction_right;
		}
		break;
	default:
		break;
	}
}
void Snake::move()
{
	pTail->setPosition(pHead->getPosition() + direction);
	pHead = pTail;
	pTail++;
	if (pTail == body.end())
	{
		pTail = body.begin();
	}
}
void Snake::grow(unique_ptr<Game_Asset_Manager>& assets)
{
	sf::Sprite new_snake_part;
	new_snake_part.setTexture(assets->Get_My_texture(snakie));
	new_snake_part.setPosition(pHead->getPosition()+direction);
	pHead = body.insert(++pHead, new_snake_part);
}
bool Snake::collision(unique_ptr<Fruit>& fruit)
{
	return fruit->get_bounds().intersects(pHead->getGlobalBounds());
}
bool Snake::goingToBumpIntoWall(unique_ptr<my_Wall>&wallee)
{
	for (int i = 0; i < 4; i++)
	{
		if (wallee->get_bounds()[i].intersects(pHead->getGlobalBounds()))
		{
			return true;
		}
	}
	return false;
}
bool Snake::hitting_itself()
{
	bool is_on = false;
	for(auto i = body.begin(); i!=body.end();i++ )
	{
		if (pHead != i)
		{
			if (i->getGlobalBounds().intersects(pHead->getGlobalBounds()))
			{
				return true;
			}
			else
			{
				is_on = false;
			}
		}
	}
	return is_on;
}
void Snake:: admit_points(int amount)
{
	points_counter+=amount;
}
int Snake::amount_of_points()
{
	return points_counter;
}
void Snake::draw(unique_ptr<sf::RenderWindow>& window)
{
	for (auto& i : body)
	{
		window->draw(i);
	}
}