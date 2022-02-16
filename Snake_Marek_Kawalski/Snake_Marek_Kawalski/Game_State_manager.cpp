#include "Game_State_manager.h"

Game_State_manager::Game_State_manager() : add_state(false), replace(false), remove(false) {};
Game_State_manager::~Game_State_manager(){}
void Game_State_manager::add(unique_ptr<Game_State>adding_new_state, bool change_state)
{
	add_state = true;
	new_state = move(adding_new_state);
	replace = change_state;
}
bool Game_State_manager:: is_empty()
{
	if (deque_of_states.empty())
	{
		return true;
	}
	else return false;
}
bool Game_State_manager::remove_state()
{
	remove = true;
	return remove;
}
void Game_State_manager::changing_states()
{
	if (remove and (not deque_of_states.empty()))
	{
		deque_of_states.pop_back();
		remove = false;
	}
	if (add_state)
	{
		deque_of_states.push_back(move(new_state));
		deque_of_states.back()->initialize();
		add_state = false;
	}
}
unique_ptr<Game_State>& Game_State_manager::get_current_state()
{
	if(not deque_of_states.empty())
	return deque_of_states.back();
}
