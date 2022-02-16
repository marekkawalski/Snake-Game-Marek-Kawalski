#include "Game.h"

Game::Game()
{
    context = make_shared<Game_Context>();
    context->window->create(sf::VideoMode(window_width, window_height), "Snake Game", sf::Style::Close);
    context->states->add(make_unique<Intro1>(context));
}
void Game::game()
{       
        sf::Clock clock;
        sf::Time time = sf::Time::Zero;
        while (context->window->isOpen())
        {
            time += clock.restart(); //this function puts the time counter back to zero
            while (time > FPS)
            {
                time -= FPS;
                context->states->changing_states();
                context->states->get_current_state()->event_handler();
                context->states->get_current_state()->update(FPS);
                context->states->get_current_state()->draw();
            }
        }
}