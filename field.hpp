#ifndef FIELD_HPP
#define FIELD_HPP

#include <QGraphicsView>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QScopedPointer>
#include "business-logic-layer.hpp"

class Field : public QGraphicsView {
    Q_OBJECT

public:
    explicit Field(QWidget *parent = nullptr);

protected:
     void dragEnterEvent(QDragEnterEvent *event);    
     void dropEvent(QDropEvent *event);

public slots:
     void clear();

private:
    const int FIELD_SIZE = 50;
    int number_of_ship[4] = {4, 3, 2, 1};
    QScopedPointer<BusinessLogicLayer> game_logic;
    QGraphicsItemGroup *ships_group;
};

#endif // FIELD_HPP
