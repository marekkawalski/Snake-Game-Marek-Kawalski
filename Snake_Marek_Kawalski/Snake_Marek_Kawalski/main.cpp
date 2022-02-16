#include "Game.h"
#include <Windows.h>
int main()
{
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE); // ZAMYKA KONSOLE WINDOWS[/cpp]
    unique_ptr<Game>game = make_unique<Game>();
    game->game();
    return 0;
}