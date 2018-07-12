#include "business-logic-layer.hpp"

#include <QDebug>

BusinessLogicLayer::BusinessLogicLayer() :
    cells_state(QVector<QVector<CellState>>(FIELD_DIMENSION))
{    
    for (int i = 0; i < FIELD_DIMENSION; ++i)
        for(int j = 0; j < FIELD_DIMENSION; ++j)
            cells_state[i].push_back(CellState::EMPTY);
}

bool BusinessLogicLayer::place_ship(const QPoint &begin, const QPoint &end)
{
   int begin_x = begin.x() == 0 ? 0 : begin.x() - 1;
   int begin_y = begin.y() == 0 ? 0 : begin.y() - 1;
   int end_x = end.x() == FIELD_DIMENSION ? FIELD_DIMENSION : end.x() + 1;
   int end_y = end.y() == FIELD_DIMENSION ? FIELD_DIMENSION : end.y() + 1;

    if (check_ship(QPoint(begin_x, begin_y), QPoint(end_x, end_y)) == false)
    {
        return false;
    }

    for (int i = begin.x(); i < end.x(); ++i)
    {
        for (int j = begin.y(); j < end.y(); j++)
            cells_state[j][i] = CellState::SHIP;
    }

    print();

    return true;
}

void BusinessLogicLayer::clear()
{
    for (int i = 0; i < FIELD_DIMENSION; ++i)
        for(int j = 0; j < FIELD_DIMENSION; ++j)
            cells_state[i][j] = CellState::EMPTY;
}

bool BusinessLogicLayer::check_ship(const QPoint &begin, const QPoint &end)
{
    for (int i = begin.x(); i < end.x(); ++i)
    {
        for (int j = begin.y(); j < end.y(); j++)
        {
            if (cells_state[j][i] == CellState::SHIP)
                return false;
        }
    }

    return true;
}
