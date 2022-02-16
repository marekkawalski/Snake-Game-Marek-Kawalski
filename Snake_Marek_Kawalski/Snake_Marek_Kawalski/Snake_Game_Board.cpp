#include "Snake_Game_Board.h"

Snake_Game_Board::Snake_Game_Board(shared_ptr<Game_Context>& context)
{
	this->context = context;
	file = "Textures/grass.png";
	fire_wall = "Textures/fire.png";
	diffrent_fruit_file = "Textures/Food.png";
	bomb_file = "Textures/bomb9.png";
	snake_start_posx = 50.f;
	snake_start_posy = 50.f;
	context->window->setMouseCursorVisible(false);
}
Snake_Game_Board::~Snake_Game_Board()
{
}
void Snake_Game_Board::initialize()
{
	speed = 0.55;
	context->assets->Add_Texture(file, true); //init grass
	grass.setTexture(context->assets->Get_My_texture(my_grass));
	grass.setTextureRect(context->window->getViewport(context->window->getDefaultView()));
	//init apple
	apple = make_unique<Fruit>();
	apple->initialize(context->window, context->assets, diffrent_fruit_file, my_apple);
	apple->fruit.setTextureRect(sf::IntRect(fruit_size * 4, fruit_size, fruit_size, fruit_size));
	apple->setPosition(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(4));
	//init walls
	wallee = make_unique<my_Wall>();
	wallee->init(context->assets, fire_wall);
	wallee->set_bounds();
	//init snake
	snake = make_unique<Snake>();
	snake->initialize(snake_start_posx, snake_start_posy, context->window, context->assets);
	//Random position on screen
	distributionx = make_unique<uniform_int_distribution<int>>(wall_size, window_width - 2 * wall_size);
	distributiony = make_unique<uniform_int_distribution<int>>(wall_size, window_height - 2 * wall_size);
	//Fruit initialization
	diffrent_fruit = make_unique<Fruit>();
	diffrent_fruit->initialize(context->window, context->assets, diffrent_fruit_file, my_diffrent_fruit);
	time_dist = make_unique<uniform_int_distribution<int>>(fruit_start_time, fruit_end_time);
	fruitx = make_unique<uniform_int_distribution<int>>(fruit_start, fruit_end);
	fruity = make_unique<uniform_int_distribution<int>>(fruit_start, fruit_end);
	diffrent_fruit->fruit.setTextureRect(sf::IntRect(fruit_size * set_random_fruit().x, fruit_size * set_random_fruit().y, fruit_size, fruit_size));

	//init sound
	eat_buffer.loadFromFile("Music/eat_sound.ogg");
	eat_sound.setBuffer(eat_buffer);
	context->bomb_buffer.loadFromFile("Music/explosion.flac");
	context->bomb_sound.setBuffer(context->bomb_buffer);
	context->death_buffer.loadFromFile("Music/death.ogg");
	context->death_sound.setBuffer(context->death_buffer);
	context->crash_buffer.loadFromFile("Music/crash.ogg");
	context->crash_sound.setBuffer(context->crash_buffer);
	context->crash_sound.setVolume(70.f);
	//init bomb
	for (int i = 1; i <= 12; i++)
	{
		if (!bombs_map[i].loadFromFile("Textures/bomb" + to_string(i) + ".png")) cout << "There is a problem with bomb file" << endl;
	}
	bomb_distributionx = make_unique<uniform_int_distribution<int>>(2 * wall_size, window_width - 2 * wall_size);
	bomb_distributiony = make_unique<uniform_int_distribution<int>>(2 * wall_size, window_height - 2 * wall_size);
	bombx = make_unique<uniform_int_distribution<int>>(bomb_start, bomb_end);
	bomb = make_unique<Fruit>();
	bomb->initialize(context->window, context->assets, bomb_file, my_bomb);
	bomb->setPosition(set_random_position(*bomb_distributionx, *bomb_distributiony).x, set_random_position(*bomb_distributionx, *bomb_distributiony).y);
	bomb->fruit.setTexture(bombs_map.at(set_random_number(*bombx)));
	disappear_buffer.loadFromFile("Music/disappear.wav");
	disappear_sound.setBuffer(disappear_buffer);
	disappear_sound.setVolume(30.f);
	//points counter
	text.setFont(context->assets->Get_My_Font(Font));
	text.setFillColor(sf::Color::Yellow);
	text.setString(to_string(snake->amount_of_points()));
	text.setOrigin(text.getLocalBounds().width / static_cast<float>(2), text.getLocalBounds().height / static_cast<float>(2));
	text.setPosition(context->window->getSize().x / static_cast<float>(1.1), context->window->getSize().y / static_cast<float>(9));
	//init bullet
	bullet.init(context->assets, context->window);
	context->shoot_buffer.loadFromFile("Music/burst.ogg");
	context->shoot_sound.setBuffer(context->shoot_buffer);
	bulletx = make_unique<uniform_int_distribution<int>>(bullet_start, bullet_end);
}
void Snake_Game_Board::event_handler()
{
	sf::Event event;
	while (context->window->pollEvent(event))
	{
		if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle) or event.type == sf::Event::Closed
			or (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
		{
			context->window->close();
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			if (event.key.code == sf::Keyboard::Space)
			{
				space_pressed = false;
			}
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			snake->snake_steering(event);
			if (event.key.code == sf::Keyboard::Space)
			{
				space_pressed = true;
				context->shoot_sound.play();
				context->shoot_sound.setVolume(30.f);
			}
			if (event.key.code == sf::Keyboard::LShift and !speed_set)
			{
				speed -= 0.25;
				speed_set = true;
				text.setFillColor(sf::Color::White);
			}
			else if (event.key.code == sf::Keyboard::LShift and speed_set)
			{
				speed += 0.25;
				speed_set = false;
				text.setFillColor(sf::Color::Yellow);
			}
			else if (event.key.code == sf::Keyboard::P)
			{
				context->shoot_sound.setLoop(false);
				context->shoot_sound.stop();
				context->move_snake = false;
				context->states->add(make_unique<Game_Pause>(context));
			}
		}
	}
}
void Snake_Game_Board::update(sf::Time time)
{
	if (space_pressed)
	{
		bullet.bullet_set_position(snake, speed);
		bullets.push_back(Bullet(bullet));
		context->shoot_sound.setLoop(true);
	}
	else if (!space_pressed)
	{
		context->shoot_sound.setLoop(false);
	}
	for (auto i = 0; i < bullets.size(); i++)
	{
		bullets[i].bullet.setTextureRect(sf::IntRect(bullet_size * set_random_number(*bulletx) + 1, 1, bullet_size, bullet_size));
		if (bullets[i].collision(apple))
		{
			apple_collision();
		}
		if (bullets[i].collision(diffrent_fruit))
		{
			diffrent_fruit_collision();
		}
		if (bullets[i].collision(bomb))
		{
			bomb->setPosition(1500, 1500);
			disappear_sound.play();
		}
		if (bullets[i].shooting_itself(snake))
		{
			snake_collision();
		}
		bullets[i].bullet.move(bullets[i].current_velocity);
		if ((bullets[i].bullet.getPosition().x < 0 + wall_size) or (bullets[i].bullet.getPosition().x > window_width - wall_size)
			or (bullets[i].bullet.getPosition().y < 0 + wall_size) or (bullets[i].bullet.getPosition().y > window_height - wall_size))
		{
			bullets.erase(bullets.begin() + i);
		}
	}

	time2 = time;
	time3 = time;
	time = sf::seconds(0.1f);
	how_much_time += time;
	how_much_time2 += time2;
	how_much_time3 += time3;
	if (how_much_time.asSeconds() > speed)
	{
		if (snake->goingToBumpIntoWall(wallee))
		{
			wall_collision();
		}
		else if (snake->hitting_itself())
		{
			snake_collision();
		}
		else if (snake->collision(bomb))
		{
			bomb_collision();
		}
		else if (snake->collision(apple))
		{
			apple_collision();
		}
		else if (snake->collision(diffrent_fruit))
		{
			diffrent_fruit_collision();
		}
		else
		{
			if (context->move_snake)
			{
				snake->move();
			}
		}
		how_much_time = sf::Time::Zero;
	}

	if (how_much_time2.asSeconds() > static_cast<float>(expectancy_time))
	{
		diffrent_fruit->setPosition(set_random_position(*distributionx, *distributiony).x, set_random_position(*distributionx, *distributiony).y);
		diffrent_fruit->fruit.setTextureRect(sf::IntRect(fruit_size * set_random_fruit().x, fruit_size * set_random_fruit().y, fruit_size, fruit_size));
		expectancy_time = set_random_number(*time_dist);
		how_much_time2 = sf::Time::Zero;
	}
	if (how_much_time3.asSeconds() > static_cast<float>(expectancy_time2))
	{
		bomb->setPosition(set_random_position(*bomb_distributionx, *bomb_distributiony).x, set_random_position(*bomb_distributionx, *bomb_distributiony).y);
		bomb->fruit.setTexture(bombs_map.at(set_random_number(*bombx)));
		expectancy_time2 = set_random_number(*time_dist);
		how_much_time3 = sf::Time::Zero;
	}
}
void Snake_Game_Board::draw()
{
	context->window->clear();
	context->window->draw(grass);
	snake->draw(context->window);
	apple->draw(context->window);
	diffrent_fruit->draw(context->window);
	wallee->draw(context->window);
	bomb->draw(context->window);
	context->window->draw(text);
	for (auto i = 0; i < bullets.size(); i++)
	{
		context->window->draw(bullets[i].bullet);
	}
	context->window->display();
}
sf::Vector2i Snake_Game_Board::set_random_position(uniform_int_distribution<int>dysx, uniform_int_distribution<int>dysy)
{
	sf::Vector2i vectorek;
	int randx = dysx(context->generator);
	int randy = dysy(context->generator);
	vectorek = { randx, randy };
	return vectorek;
}
sf::Vector2i Snake_Game_Board::set_random_fruit()
{
	sf::Vector2i vectorek;
	int randx = (*fruitx)(context->generator);
	int randy = (*fruity)(context->generator);
	vectorek = { randx, randy };
	return vectorek;
}
int Snake_Game_Board::set_random_number(uniform_int_distribution<int>dys)
{
	int mus;
	mus = dys(context->generator);
	return mus;
}
void Snake_Game_Board::apple_collision()
{
	eat_sound.play();
	snake->grow(context->assets);
	apple->setPosition(set_random_position(*distributionx, *distributiony).x, set_random_position(*distributionx, *distributiony).y);
	snake->admit_points(1);
	speed -= 0.007;
	text.setString(to_string(snake->amount_of_points()));
}
void Snake_Game_Board::diffrent_fruit_collision()
{
	eat_sound.play();
	snake->grow(context->assets);
	diffrent_fruit->setPosition(1000, 1000);
	snake->admit_points(2);
	speed -= 0.01;
	text.setString(to_string(snake->amount_of_points()));
}
void Snake_Game_Board::bomb_collision()
{
	context->bomb_sound.play();
	context->points_quantity = snake->amount_of_points();
	context->window->setMouseCursorVisible(true);
	context->states->remove_state();
	context->shoot_sound.setLoop(false);
	context->states->add(make_unique<End_of_game>(context));
}
void Snake_Game_Board::snake_collision()
{
	context->death_sound.play();
	eat_sound.stop();
	context->points_quantity = snake->amount_of_points();
	context->window->setMouseCursorVisible(true);
	context->states->remove_state();
	context->shoot_sound.setLoop(false);
	context->states->add(make_unique<End_of_game>(context));
}
void Snake_Game_Board::wall_collision()
{
	context->crash_sound.play();
	eat_sound.stop();
	context->points_quantity = snake->amount_of_points();
	context->window->setMouseCursorVisible(true);
	context->states->remove_state();
	context->shoot_sound.setLoop(false);
	context->states->add(make_unique<End_of_game>(context));
}