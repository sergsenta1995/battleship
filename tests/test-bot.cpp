#include <QTest>

class Test_Bot : public QObject {
    Q_OBJECT
private slots:
    void temp()
    {
        QVERIFY(true);
    }
};


QTEST_MAIN(Test_Bot)
#include "test-bot.moc"
