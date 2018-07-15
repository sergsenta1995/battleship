#ifndef BOT_H
#define BOT_H

#include <functional>
#include <vector>

class Bot {
public:
    Bot();

    bool generateRotation();
    int generateSide();
    std::vector<int> generatePositionShip(int number_of_desk,
                                          bool rotation);
    void chooseStrategyFor4DeskShip();
    void chooseStrategyFor2DeskShip();
private:
    std::function<void(int&, int&, bool)> strategy;

    void starategyByDefault(int &, int&, bool){}
    void strategyGeneratedOnSide(int &x, int &y, bool rotation);
    void strategyGeneratedInside(int &x, int &y, bool rotation);
    const int LENGTH_FIELD = 10;
};

#endif // BOT_H
