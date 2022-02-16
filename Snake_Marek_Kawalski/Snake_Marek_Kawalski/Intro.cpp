#include "Intro.h"
#include "Menu.h"
#include "Game.h"

Intro::Intro(shared_ptr<Game_Context>& context)
{
    this->context = context;
}
void Intro::initialize()
{
    string file = "Textures/snake-intro.png";
    context->assets->Add_Texture(file, false);
    picture.setTexture(context->assets->Get_My_texture(snake_intro));
}
void Intro::event_handler()
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
            context->states->add(make_unique<Menu>(context));
        }
    }
}
void Intro::update(sf::Time time)
{

}
void Intro::draw()
{
    picture.setScale(1.3, 1.4);
    context->window->clear();
    context->window->draw(picture);
    context->window->display();
}