#include <QTest>
#include "../bot.hpp"
#include <iostream>

class Test_Bot : public QObject {
    Q_OBJECT

private slots:
    void testGeneratePositionShip()
    {
        Bot bot;

        for (int number_of_desk = 1; number_of_desk < 5; ++number_of_desk)
        {
            ShipPosition result = bot.generatePositionShip(number_of_desk);
            bool check_condition = (result.x_begin == result.x_end - (number_of_desk - 1)) ||
                                   (result.y_begin == result.y_end - (number_of_desk - 1));
            QVERIFY(check_condition);
        }
    }

    void testGenerateStrategyFor2DeskShip()
    {
        Bot bot;
        bot.chooseStrategyFor1and2DeskShip();

        for (int number_of_desk = 2; number_of_desk < 1; --number_of_desk)
        {
            ShipPosition result = bot.generatePositionShip(number_of_desk);
            // В соответствии со стратегией размещения малых кораблей (2-х и 1-о палубных)
            // корабль должен быть размещен в центре поля, т. е. отступая от краев поля.
            bool check_condition = (result.x_begin == result.x_end - (number_of_desk - 1)) ||
                                   (result.y_begin == result.y_end - (number_of_desk - 1)) &&
                                   (result.x_begin > 0 && result.x_end < 9 && result.y_begin > 0 && result.y_end < 9);
            QVERIFY(check_condition);
        }
    }

    void testGenerateStrategyFor4DeskShip()
    {
        Bot bot;
        bot.chooseStrategyFor4and3DeskShip();

        for (int number_of_desk = 4; number_of_desk > 2; --number_of_desk)
        {
            ShipPosition result = bot.generatePositionShip(number_of_desk);
            // В соответствии со стратегией размещения больших кораблей (3-х и 4-х палубных)
            // корабль должен быть размещен на краю.
            bool x_condition = ((result.x_begin == 9 && result.x_end == 9) && (result.y_begin == result.y_end - (number_of_desk - 1))) ||
                               ((result.x_begin == 0 && result.x_end == 0) && (result.y_begin == result.y_end - (number_of_desk - 1)));
            bool y_condition = ((result.y_begin == 9 && result.y_end == 9) && (result.x_begin == result.x_end - (number_of_desk - 1))) ||
                               ((result.y_begin == 0 && result.y_end == 0) && (result.x_begin == result.x_end - (number_of_desk - 1)));
            QVERIFY(x_condition || y_condition);
        }
    }

    void testPlaceShip()
    {
        Bot bot1;
        bot1.placeShips();
    }
};


QTEST_MAIN(Test_Bot)
#include "test-bot.moc"
