#include "business-logic-layer.hpp"

#include <QDebug>

BusinessLogicLayer::BusinessLogicLayer() :
    cells_state(QVector<QVector<CellState>>(FIELD_DIMENSIOM))
{
    for (int i = 0; i < FIELD_DIMENSIOM; ++i)
        for(int j = 0; j < FIELD_DIMENSIOM; ++j)
            cells_state[i].push_back(CellState::EMPTY);
}

bool BusinessLogicLayer::place_ship(const QPoint &begin, const QPoint &end)
{
    qDebug()<< begin << end;

    QPoint check_begin(begin.x() - 1, begin.y() - 1);
    QPoint check_end(end.x() + 1, end.y() + 1);

    if (check_ship(check_begin, check_end) == false)
        return false;

    for (int i = begin.x(); i < end.x(); ++i)
    {
        for (int j = begin.y(); j < end.y(); j++)
            cells_state[j][i] = CellState::SHIP;
    }

    print();

    return true;
}

bool BusinessLogicLayer::check_ship(const QPoint &begin, const QPoint &end)
{
    for (int i = begin.x(); i < end.x(); ++i)
    {
        for (int j = begin.y(); j < end.y(); j++)
            if (cells_state[j][i] == CellState::SHIP)
                return false;
    }

    return true;
}
