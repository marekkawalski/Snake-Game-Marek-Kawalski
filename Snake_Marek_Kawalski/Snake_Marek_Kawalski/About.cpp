#include "About.h"

About::About(shared_ptr<Game_Context> &context)
{
    this->context = context;
}

void About::initialize()
{
    button_back = make_unique<Button>(context->window->getSize().x / static_cast<float>(4.0 / 3.5), context->window->getSize().y / static_cast<float>(4.0 / 3.5), 160, 60, 24, context->assets->Get_My_Font(Font), "Back", sf::Color(255, 255, 255), sf::Color(053, 104, 045), sf::Color::Yellow, sf::Color(250, 210, 001));
    text.setFont(context->assets->Get_My_Font(Font));
    text.setFillColor(sf::Color::Yellow);
    some_text = "Snake Game quick manual";
    text.setString(some_text);
    text.setOrigin(text.getLocalBounds().width / static_cast<float>(2), text.getLocalBounds().height / static_cast<float>(2));
    text.setPosition(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(12));
    more_text.setFont(context->assets->Get_My_Font(Font));
    more_text.setFillColor(sf::Color::Yellow);
    m_text_string = "To play use W,S,D,A keys or use arrows\nYou will get a point for every apple you grab. Twice as much will be given to you\nif you grab diffrent fruits. If you hit either the wall or a bomb the game will be over.\nThe same will happen once you hit your own body.\nGood Luck and have fun!";
    more_text.setString(m_text_string);
    more_text.setCharacterSize(22);
    more_text.setOrigin(more_text.getLocalBounds().width / static_cast<float>(2), more_text.getLocalBounds().height / static_cast<float>(2));
    more_text.setPosition(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(3));
}
void About::event_handler()
{
    sf::Event event;
    while (context->window->pollEvent(event))
    {
        if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle) or event.type == sf::Event::Closed or (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        {
            context->window->close();
        }
        button_back->change_color(context->window);
        if (button_back->is_button_pressed or sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            context->states->remove_state();
            context->states->add(make_unique<Menu>(context));
        }
    }
}
void About::update(sf::Time time)
{
}
void About::draw()
{
    context->window->clear(sf::Color(154, 205, 50));
    button_back->display(context->window);
    context->window->draw(text);
    context->window->draw(more_text);
    context->window->display();
}
About::~About() {}
