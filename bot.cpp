#include <bot.hpp>
#include <random>
#include <ctime>
#include <iostream>

Bot::Bot()
{
    srand(time(NULL));

    strategy = std::bind(&Bot::starategyByDefault,
                         this,
                         std::placeholders::_1,
                         std::placeholders::_2,
                         std::placeholders::_3);
}

bool Bot::generateRotation()
{
    return rand() % 2;
}

int Bot::generateSide()
{
    return (rand() % 2) * (LENGTH_FIELD - 1);
}

std::vector<int> Bot::generatePositionShip(int number_of_desk,
                                           bool rotation)//,
                                           //std::function<void(int &, int &)> strategy)
{
    int x_begin = rand() % (LENGTH_FIELD - number_of_desk);
    int y_begin = rand() % (LENGTH_FIELD - number_of_desk);

    if (rotation)
    {
        strategy(x_begin, y_begin, rotation);

        int x_end = x_begin;
        int y_end = y_begin + number_of_desk;

        std::cout << x_begin << " " << x_end << " " << y_begin << " " << y_end << std::endl;
        return {x_begin, x_end, y_begin, y_end};
    }

    strategy(x_begin, y_begin, rotation);

    int y_end = y_begin;
    int x_end = x_begin + number_of_desk;

    std::cout << "rotated " << x_begin << " " << x_end << " " << y_begin << " " << y_end << std::endl;

    return {x_begin, x_end, y_begin, y_end};
}

void Bot::chooseStrategyFor4DeskShip()
{
    strategy = std::bind(&Bot::strategyGeneratedOnSide,
                         this,
                         std::placeholders::_1,
                         std::placeholders::_2,
                         std::placeholders::_3);
}

void Bot::chooseStrategyFor2DeskShip()
{
    strategy = std::bind(&Bot::strategyGeneratedInside,
                         this,
                         std::placeholders::_1,
                         std::placeholders::_2,
                         std::placeholders::_3);
}

void Bot::strategyGeneratedOnSide(int &x, int &y, bool rotation)
{
    if (rotation)
        x = x % 2 * (LENGTH_FIELD - 1);
    else
        y = y % 2 * (LENGTH_FIELD - 1);
}

void Bot::strategyGeneratedInside(int &x, int &y, bool rotation)
{
    if (x == 0)
        x = 1;
    if (x > 1)
        --x;

    if (y == 0)
        y = 1;
    if (y > 1)
        --y;
}

