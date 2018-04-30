#ifndef BUSINESS_LOGIC_LAYER_HPP
#define BUSINESS_LOGIC_LAYER_HPP

#include <QObject>
#include <QVector>
#include <QPoint>

#include <QDebug>

class BusinessLogicLayer : QObject {
    Q_OBJECT

public:
    explicit BusinessLogicLayer();
    ~BusinessLogicLayer(){}
    bool place_ship(const QPoint &begin, const QPoint &end);

    void print()
    {
        for (int i = 0; i < 10; ++i)
        {
            QString s;
            for (int j = 0; j < 10; j++)
            {
                if (cells_state[i][j] == CellState::EMPTY)
                    s+= " EMPTY ";
                else
                    s+= "*SHIP* ";
            }
            qDebug() << s;
        }

        qDebug() << "===================";
    }

private:
    bool check_ship(const QPoint &begin, const QPoint &end);

    enum CellState{EMPTY, SHIP, HITING};
    const int FIELD_DIMENSIOM = 10;
    QVector<QVector<CellState> > cells_state;
};

#endif // BUSINESS_LOGIC_LAYER_HPP
