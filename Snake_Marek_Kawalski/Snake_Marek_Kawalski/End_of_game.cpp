#include "End_of_game.h"
End_of_game::End_of_game(shared_ptr<Game_Context>& context)
{
	this->context = context;
}
void End_of_game::initialize()
{
	button_play_again = make_unique<Button>(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(16.0 / 7.0), 160, 60, 24, context->assets->Get_My_Font(Font), "Play again", sf::Color(255, 255, 255), sf::Color(053, 104, 045), sf::Color::Yellow, sf::Color(250, 210, 001));
	button_exit = make_unique<Button>(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(16.0 / 13.0), 160, 60, 24, context->assets->Get_My_Font(Font), "Exit", sf::Color(255, 255, 255), sf::Color(053, 104, 045), sf::Color::Yellow, sf::Color(250, 210, 001));
	button_menu = make_unique<Button>(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(16.0 / 10.0), 160, 60, 24, context->assets->Get_My_Font(Font), "Menu", sf::Color(255, 255, 255), sf::Color(053, 104, 045), sf::Color::Yellow, sf::Color(250, 210, 001));
	endText.setFont(context->assets->Get_My_Font(Font));
	endText.setFillColor(sf::Color::Blue);
	text.setFont(context->assets->Get_My_Font(Font));
	text.setFillColor(sf::Color::Yellow);
	text.setString("Your Score: " + to_string(context->points_quantity) + " points");
	text.setOrigin(text.getLocalBounds().width / static_cast<float>(2), text.getLocalBounds().height / static_cast<float>(2));
	text.setPosition(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(3.5));
	map_of_texts_1[0] = "You can do better!";
	map_of_texts_1[1] = "It will be better next time!";
	map_of_texts_1[2] = "Don't warry. Give it another shot.";
	map_of_texts_1[3] = "Practice makes champion.";
	map_of_texts_1[4] = "You'll beat it next time.";
	map_of_texts_1[5] = "Not too great.";
	map_of_texts_2[0] = "Not too bad!";
	map_of_texts_2[1] = "Descend job.";
	map_of_texts_2[2] = "You are on the right path.";
	map_of_texts_2[3] = "You will nail it soon.";
	map_of_texts_2[4] = "Nice one.";
	map_of_texts_2[5] = "Doing quite well.";
	map_of_texts_3[0] = "Mesmerizing job!";
	map_of_texts_3[1] = "Astonishing result!";
	map_of_texts_3[2] = "Wow, you are truly amazing.";
	map_of_texts_3[3] = "Wonderful job!";
	map_of_texts_3[4] = "You are a genious!";
	map_of_texts_3[5] = "You can be proud of yourself.";
	//setting max score
	max_point = read_from_file("Text.bin");
	if (context->points_quantity > max_point)
	{
		save_to_file("Text.bin");
		max_score_text.setString("Previous Max Score : " + to_string(max_point) + " points");
	}
	else
	{
		max_score_text.setString("Max Score : " + to_string(max_point) + " points");
	}
	max_score_text.setFont(context->assets->Get_My_Font(Font));
	max_score_text.setFillColor(sf::Color::Red);
	max_score_text.setOrigin(max_score_text.getLocalBounds().width / static_cast<float>(2), max_score_text.getLocalBounds().height / static_cast<float>(2));
	max_score_text.setPosition(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(5));
	set_points();
}
void End_of_game::event_handler()
{
	sf::Event event;
	while (context->window->pollEvent(event))
	{
		if ((event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Middle) or event.type == sf::Event::Closed
			or (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)))
		{
			context->states->remove_state();
			context->window->close();
		}
		button_play_again->change_color(context->window);
		button_exit->change_color(context->window);
		button_menu->change_color(context->window);
		if (button_play_again->is_button_pressed or sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			context->states->remove_state();
			context->states->add(make_unique<Snake_Game_Board>(context));
		}
		else if (button_menu->is_button_pressed)
		{
			context->states->remove_state();
			context->states->add(make_unique<Menu>(context));
		}
		else if (button_exit->is_button_pressed)
		{
			context->crash_sound.stop();
			context->window->close();
		}
	}
}
void End_of_game::update(sf::Time time)
{
}
void End_of_game::set_points()
{
	if (context->points_quantity > max_point)
	{
		endText.setString("Congratulations. New High score!!!");
	}
	else
	{
		random_number = (context->points_quantity) % 6;
		if (context->points_quantity < 10)
		{
			endText.setString(map_of_texts_1.at(random_number));
		}
		else if (context->points_quantity < 15)
		{
			endText.setString(map_of_texts_2.at(random_number));
		}
		else if (context->points_quantity > 15)
		{
			endText.setString(map_of_texts_3.at(random_number));
		}
	}
	endText.setOrigin(endText.getLocalBounds().width / static_cast<float>(2), endText.getLocalBounds().height / static_cast<float>(2));
	endText.setPosition(context->window->getSize().x / static_cast<float>(2), context->window->getSize().y / static_cast<float>(8));
}
void End_of_game::draw()
{
	context->window->clear(sf::Color(154, 205, 50));
	button_play_again->display(context->window);
	button_exit->display(context->window);
	button_menu->display(context->window);
	context->window->draw(endText);
	context->window->draw(text);
	context->window->draw(max_score_text);
	context->window->display();
}
int End_of_game::read_from_file(string filename)
{
	ifstream file;
	file.open(filename, ios_base::binary);
	if (file.good() == false)
	{
		cout << "Blad z plikiem wejsciowym" << endl;
		file.close();
	}
	int max_wynik;
	file >> max_wynik;
	file.close();
	return max_wynik;
}
void End_of_game::save_to_file(string filename)
{
	ofstream file;
	file.open(filename, ios_base::binary);
	if (file.good() == false)
	{
		cout << "Blad z plikiem wyjsciowym" << endl;
		file.close();
	}
	file << context->points_quantity;
	file.close();
}