#include <QTest>
#include "../bot.hpp"

class Test_Bot : public QObject {
    Q_OBJECT
private slots:
    void testGenerateShip()
    {
        int number_of_desk = 4;
        std::vector<int> result = bot.generatePositionShip(number_of_desk, false);

        QVERIFY(result.at(Y_BEGIN) == result.at(Y_END));
        QVERIFY(result.at(X_BEGIN) + number_of_desk == result.at(X_END));

        number_of_desk = 3;
        result = bot.generatePositionShip(number_of_desk, true);

        QVERIFY(result.at(X_BEGIN) == result.at(X_END));
        QVERIFY(result.at(Y_BEGIN) + number_of_desk == result.at(Y_END));
    }

private:
    Bot bot;

    const int X_BEGIN = 0;
    const int X_END   = 1;
    const int Y_BEGIN = 2;
    const int Y_END   = 3;
};


QTEST_MAIN(Test_Bot)
#include "test-bot.moc"
