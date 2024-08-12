#include "app.h"
#include <iostream>
#include <stdexcept>

int main()
{
    App game;
    
    try
    {
        game.Init(800,600, "Mineraft Clone");
        game.Run();
    } 
    catch (std::runtime_error &e)
    {
        std::cerr << "Exeption:" << e.what() << std::endl;
    }


    return 0;
}
