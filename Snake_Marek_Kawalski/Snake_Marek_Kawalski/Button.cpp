#include "Button.h"

Button::Button(float x, float y, float width, float height, int size, const sf::Font& font, string text, sf::Color fillColor, sf::Color idleColor, sf::Color hoverColor, sf::Color avtiveColor)
{
	is_button_pressed = false;
	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(width, height));
	idle = idleColor;
	hover = hoverColor;
	active = avtiveColor;
	this->font = font;
	this->text.setFont(this->font);
	this->text.setString(text);
	this->text.setCharacterSize(size);
	this->text.setFillColor(fillColor);
	shape.setOrigin(shape.getLocalBounds().width / static_cast<float>(2), shape.getLocalBounds().height / static_cast<float>(2));
	this->text.setOrigin(this->text.getLocalBounds().width / static_cast<float>(2), this->text.getLocalBounds().height / static_cast<float>(2));
	this->text.setPosition(x, y);
	shape.setFillColor(idle);
}
bool Button::mouse_over(unique_ptr<sf::RenderWindow>& window)
{
	float mouseX = sf::Mouse::getPosition(*window).x;
	float mouseY = sf::Mouse::getPosition(*window).y;
	float btnX = shape.getPosition().x;
	float btnY = shape.getPosition().y;
	float btnXPosition_plus_width = shape.getPosition().x + shape.getLocalBounds().width / static_cast<float>(2);
	float btnYPosition_plus_height = shape.getPosition().y + shape.getLocalBounds().height / static_cast<float>(2);
	if (mouseX<btnXPosition_plus_width && mouseX>btnX - shape.getLocalBounds().width / static_cast<float>(2) &&
		mouseY<btnYPosition_plus_height && mouseY>btnY - shape.getLocalBounds().height / static_cast<float>(2))
	{
		return true;
	}
	return false;
}
void Button::change_color(unique_ptr<sf::RenderWindow>& window)
{
	if (mouse_over(window))
	{
		text.setFillColor(sf::Color(053, 104, 045));
		shape.setFillColor(hover);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			shape.setFillColor(active);
			is_button_pressed = true;
		}
	}
	else
	{
		text.setFillColor(sf::Color::Yellow);
		shape.setFillColor(idle);
	}
}
void Button::display(unique_ptr<sf::RenderWindow>& window)
{
	window->draw(shape);
	window->draw(text);
}