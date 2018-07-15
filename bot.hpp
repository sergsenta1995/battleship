#ifndef BOT_H
#define BOT_H


#include <vector>

class Bot {
public:
    Bot();

    bool generateRotation();
    int generateSide();
    std::vector<int> generatePositionShip(int number_of_desk, bool rotation);

private:
    const int LENGTH_FIELD = 10;
};

#endif // BOT_H
