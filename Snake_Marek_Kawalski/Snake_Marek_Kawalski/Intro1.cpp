#include "Intro1.h"
#include "Intro.h"
Intro1::Intro1(shared_ptr<Game_Context>& context1)
{
	context = context1;
}
void Intro1::initialize()
{
	string file = "Fonts/IndieFlower-Regular.ttf";
	context->assets->Add_Font(file);
	text.setFont(context->assets->Get_My_Font(Font));
	text.setString("Bike game developement presents...");
	text.setOrigin(text.getLocalBounds().width / static_cast<float>(2), text.getLocalBounds().height / static_cast<float>(2));
	text.setPosition(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(2));
}
void Intro1::event_handler()
{
	sf::Event event;
	while (context->window->pollEvent(event))
	{
		if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle) or event.type == sf::Event::Closed
			or (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
		{
			context->window->close();
		}
		if (is_any_key_pressed())
		{
			context->states->remove_state();
			context->states->add(make_unique<Intro>(context));
		}
	}
}
void Intro1::update(sf::Time time)
{
}
void Intro1::draw()
{
	context->window->clear();
	context->window->draw(text);
	context->window->display();
}