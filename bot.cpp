#include <bot.hpp>
#include <random>
#include <ctime>

Bot::Bot()
{
    srand(time(NULL));
}

bool Bot::generateRotation()
{
    return rand() % 2;
}

int Bot::generateSide()
{
    return (rand() % 2) * (LENGTH_FIELD - 1);
}

std::vector<int> Bot::generatePositionShip(int number_of_desk, bool rotation)
{
    int x_begin = rand() % (LENGTH_FIELD - number_of_desk);
    int y_begin = rand() % (LENGTH_FIELD - number_of_desk);

    if (rotation)
    {
        int x_end = x_begin;
        int y_end = y_begin + number_of_desk;

        return {x_begin, x_end, y_begin, y_end};
    }

    int y_end = y_begin;
    int x_end = x_begin + number_of_desk;

    return {x_begin, x_end, y_begin, y_end};
}

