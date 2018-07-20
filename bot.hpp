#ifndef BOT_H
#define BOT_H

#include <functional>
#include <vector>
#include <array>
#include <iostream>

struct ShipPosition {
    ShipPosition(){}

    ShipPosition(int x_begin_, int x_end_, int y_begin_, int y_end_) :
        x_begin(x_begin_),
        x_end(x_end_),
        y_begin(y_begin_),
        y_end(y_end_){}

    int x_begin = 0;
    int x_end   = 0;
    int y_begin = 0;
    int y_end   = 0;
};

class Bot {
public:

    Bot();
    void chooseStrategyFor4and3DeskShip();
    void chooseStrategyFor1and2DeskShip();
    ShipPosition generatePositionShip(int number_of_desk);
    void placeShips();
    bool checkPosition(ShipPosition ship_position);
    void setupShip(ShipPosition ship_position);

private:

    bool generateRotation();
    void starategyByDefault(int &, int&, bool){}
    void strategyGeneratedOnSide(int &x, int &y, bool rotation);
    void strategyGeneratedInside(int &x, int &y, bool rotation);
    ShipPosition createArea(ShipPosition ship_position);

    const int LENGTH_FIELD = 10;
    std::array<std::array<int, 10>, 10> field = {};
    std::function<void(int&, int&, bool)> strategy;
};

#endif // BOT_H
