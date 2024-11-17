#include "Game.h"
#include <iostream>

int main()
{
    try
    {
        std::cout << "Starting the game..." << std::endl;
        Game game;
        game.run();
        std::cout << "Game exited normally." << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Fatal Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
