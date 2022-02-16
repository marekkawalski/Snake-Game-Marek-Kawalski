#include "Menu.h"
Menu::Menu(shared_ptr<Game_Context>& context)
{
    this->context = context;
}
void Menu::initialize()
{  
    button_play = make_unique<Button>(context->window->getSize().x/static_cast<float>(2), context->window->getSize().y/static_cast<float>(4), 160, 60, 24, context->assets->Get_My_Font(Font),"Play",sf::Color (255, 255, 255), sf::Color (053, 104, 045),sf::Color::Yellow,sf::Color (250, 210, 001));
    button_how_to = make_unique<Button>(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(2), 160, 60, 24, context->assets->Get_My_Font(Font), "How to play", sf::Color(255, 255, 255), sf::Color (053, 104, 045), sf::Color::Yellow, sf::Color (250, 210, 001));
    button_exit = make_unique<Button>(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(4.0/3.0), 160, 60, 24, context->assets->Get_My_Font(Font), "Exit", sf::Color(255, 255, 255), sf::Color (053, 104, 045), sf::Color::Yellow, sf::Color(250, 210, 001));
    texttt.setFont(context->assets->Get_My_Font(Font));
    texttt.setString("Main Menu");
    texttt.rotate(-60.0);
    texttt.setLetterSpacing(6.f);
    texttt.setCharacterSize(45);
    texttt.setOrigin(texttt.getLocalBounds().width / static_cast<float>(2), texttt.getLocalBounds().height / static_cast<float>(2));
    texttt.setPosition(context->window->getSize().x / static_cast<float>(6.5), context->window->getSize().y / static_cast<float>(2));
    texttt2.setFont(context->assets->Get_My_Font(Font));
    texttt2.setString("Main Menu");
    texttt2.rotate(-60.0);
    texttt2.setLetterSpacing(6.f);
    texttt2.setCharacterSize(45);
    texttt2.setOrigin(texttt2.getLocalBounds().width / static_cast<float>(2), texttt2.getLocalBounds().height / static_cast<float>(2));
    texttt2.setPosition(context->window->getSize().x / static_cast<float>(1.3), context->window->getSize().y / static_cast<float>(2));
}
void Menu::event_handler()
{
    sf::Event event;
    while (context->window->pollEvent(event))
    {
        if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle) or event.type == sf::Event::Closed
            or (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
        {
            context->window->close();
        } 
        button_play->change_color(context->window);
        button_how_to->change_color(context->window);
        button_exit->change_color(context->window);
        if (button_play->is_button_pressed or sf::Keyboard::isKeyPressed(sf::Keyboard::Space) or sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            context->states->remove_state();
            context->states->add(make_unique<Snake_Game_Board>(context));
        }
        if (button_how_to->is_button_pressed)
        {
            context->states->remove_state();
            context->states->add(make_unique<About>(context));
        }
        if (button_exit->is_button_pressed)
        {
            context->window->close();
        }
    }
}
void Menu::update(sf::Time time)
{
}
void Menu::draw() 
{
    context->window->clear(sf::Color(154, 205, 50));
    button_play->display(context->window);
    button_how_to->display(context->window);
    button_exit->display(context->window);
    context->window->draw(texttt);
    context->window->draw(texttt2);
    context->window->display();
}

