#include "wall.h"

my_Wall::my_Wall()
{

}
void my_Wall::init(unique_ptr<Game_Asset_Manager>&assets, string& file)
{
    assets->Add_Texture(file, true);
    for (auto& i : walls)
    {
        i.setTexture(assets->Get_My_texture(my_wall));
    }
    walls[0].setTextureRect({ 0,0,window_width, wall_size });
    walls[1].setTextureRect({ 0,0,window_width,wall_size });
    walls[1].setPosition(0, window_height - wall_size);
    walls[2].setTextureRect({ 0,0,wall_size,window_height });
    walls[3].setTextureRect({ 0,0,wall_size,window_height });
    walls[3].setPosition(window_width - wall_size, 0);
}
void my_Wall::set_bounds()
{
    for (int i = 0; i < 4; i++)
    {
        wallie[i] = (walls[i].getGlobalBounds());
    }
}
 array<sf::FloatRect, 4> my_Wall::get_bounds()
{
    return wallie;
}
void my_Wall:: draw(unique_ptr<sf::RenderWindow>& window)
{
    for (auto& i : walls)
    {
        window->draw(i);
    }
}
