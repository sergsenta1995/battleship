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

ShipPosition Bot::generatePositionShip(int number_of_desk)
{
    int x_begin = rand() % (LENGTH_FIELD - 1 - (number_of_desk - 1));
    int y_begin = rand() % (LENGTH_FIELD - 1 - (number_of_desk - 1));
    bool rotation = generateRotation();

    if (rotation)
    {
        strategy(x_begin, y_begin, rotation);
        int x_end = x_begin;
        int y_end = y_begin + number_of_desk - 1;

        return ShipPosition(x_begin, x_end, y_begin, y_end);
    }

    strategy(x_begin, y_begin, rotation);
    int y_end = y_begin;
    int x_end = x_begin + number_of_desk - 1;

    return ShipPosition(x_begin, x_end, y_begin, y_end);
}

void Bot::placeShips()
{
    int number_of_ship = 1;
    chooseStrategyFor4and3DeskShip();
    for (int number_of_desks = 4; number_of_desks > 2; --number_of_desks, ++number_of_ship)
    {
        for (int n = 0; n < number_of_ship; ++n)
        {
            auto ship_position = generatePositionShip(number_of_desks);
            while(!checkPosition(ship_position))
            {
                ship_position = generatePositionShip(number_of_desks);
            }

            setupShip(ship_position);
        }
    }

    number_of_ship = 3;
    chooseStrategyFor1and2DeskShip();
    for (int number_of_desks = 2; number_of_desks > 0; --number_of_desks, ++number_of_ship)
    {
        for (int n = 0; n < number_of_ship; ++n)
        {
            auto ship_position = generatePositionShip(number_of_desks);
            while(!checkPosition(ship_position))
            {
                ship_position = generatePositionShip(number_of_desks);
            }

            setupShip(ship_position);
        }
    }
}

void Bot::chooseStrategyFor4and3DeskShip()
{
    strategy = std::bind(&Bot::strategyGeneratedOnSide,
                         this,
                         std::placeholders::_1,
                         std::placeholders::_2,
                         std::placeholders::_3);
}

void Bot::chooseStrategyFor1and2DeskShip()
{
    strategy = std::bind(&Bot::strategyGeneratedInside,
                         this,
                         std::placeholders::_1,
                         std::placeholders::_2,
                         std::placeholders::_3);
}

bool Bot::checkPosition(ShipPosition ship_position)
{
    //std::cout << "check  " << ship_position.x_begin << " " << ship_position.x_end << " " << ship_position.y_begin << " " << ship_position.y_end << std::endl;

    for (int i = ship_position.y_begin ; i < ship_position.y_end+1; ++i)
    {
        for (int j = ship_position.x_begin; j < ship_position.x_end+1; ++j)
        {
            if (field[i][j] == 1)
                return false;
        }
    }

    return true;
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

ShipPosition Bot::createArea(ShipPosition ship_position)
{
    if (ship_position.x_begin > 0 || ship_position.x_begin == LENGTH_FIELD - 1)
        --ship_position.x_begin;

    if (ship_position.x_end < LENGTH_FIELD - 1)
        ship_position.x_end+=2;
    else
        ++ship_position.x_end;

    if (ship_position.y_begin > 0 || ship_position.y_begin == LENGTH_FIELD -1)
        --ship_position.y_begin;

    if (ship_position.y_end < LENGTH_FIELD - 1)
        ship_position.y_end +=2;
    else
        ++ship_position.y_end;

    return ship_position;
}

void Bot::setupShip(ShipPosition ship_position)
{
    ship_position = createArea(ship_position);

    for (int i = ship_position.y_begin ; i < ship_position.y_end; ++i)
    {
        for (int j = ship_position.x_begin; j < ship_position.x_end ; ++j)
        {
            field[i][j] = 1 ;
        }
    }
}

