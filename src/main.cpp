#include "game.h"

int main()
{
    Game game;
    int result = game.Init();
    if (result != 0)
        return result;

    result = game.Run();

    return result;
}
