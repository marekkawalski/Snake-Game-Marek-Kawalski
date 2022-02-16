#include "Bullet.h"

Bullet::Bullet():current_velocity(0.f, 0.f)
{
}
void Bullet::init(unique_ptr<Game_Asset_Manager>& assets, unique_ptr<sf::RenderWindow>& window)
{
	bullet_file = "Textures/small_jewels.png";
	assets->Add_Texture(bullet_file, false);
	bullet.setTexture(assets->Get_My_texture(my_bullet));
	bullet.setTextureRect(sf::IntRect(bullet_size+1, 1, bullet_size, bullet_size));
}
void Bullet::bullet_set_position(unique_ptr<Snake>&snake,double speed)
{
	bullet.setPosition(snake->pHead->getPosition() + snake->direction);
	current_velocity = snake->direction *static_cast<float>(4*speed);
}
bool Bullet::collision(unique_ptr<Fruit>& fruit)
{
	return fruit->get_bounds().intersects(bullet.getGlobalBounds());
}
bool Bullet::shooting_itself(unique_ptr<Snake>& snake)
{
	bool is_on = false;
	for (auto i = snake->body.begin(); i != snake->body.end(); i++)
	{
		if (snake->pHead != i)
		{
			if (i->getGlobalBounds().intersects(bullet.getGlobalBounds()))
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