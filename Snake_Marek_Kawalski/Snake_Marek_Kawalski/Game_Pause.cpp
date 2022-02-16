#include "Game_Pause.h"
Game_Pause::Game_Pause(shared_ptr<Game_Context>& context)
{
	this->context = context;
}
void Game_Pause::initialize()
{
	button_resume = make_unique<Button>(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(2), 160, 60, 24, context->assets->Get_My_Font(Font), "Resume", sf::Color(255, 255, 255), sf::Color(053, 104, 045), sf::Color::Yellow, sf::Color(250, 210, 001));
	button_exit = make_unique<Button>(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(4.0f / 3.0f), 160, 60, 24, context->assets->Get_My_Font(Font), "Exit", sf::Color(255, 255, 255), sf::Color(053, 104, 045), sf::Color::Yellow, sf::Color(250, 210, 001));
	context->window->setMouseCursorVisible(true);
	text.setFont(context->assets->Get_My_Font(Font));
	text.setFillColor(sf::Color::White);
	text.setString("Game paused");
	text.setOrigin(text.getLocalBounds().width / static_cast<float>(2), text.getLocalBounds().height / static_cast<float>(2));
	text.setPosition(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(7));
}
void Game_Pause::event_handler()
{
	sf::Event event;
	while (context->window->pollEvent(event))
	{
		button_resume->change_color(context->window);
		button_exit->change_color(context->window);

		if (button_exit->is_button_pressed or sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			context->window->close();
		}
		else if (button_resume->is_button_pressed or sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) or sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			context->move_snake = true;
			context->window->setMouseCursorVisible(false);
			context->states->remove_state();
		}
	}
}
void Game_Pause::update(sf::Time time)
{
}
void Game_Pause::draw()
{
	button_resume->display(context->window);
	button_exit->display(context->window);
	context->window->draw(text);
	context->window->display();
}