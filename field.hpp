#ifndef FIELD_HPP
#define FIELD_HPP

#include <QGraphicsView>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QScopedPointer>
#include "business-logic-layer.hpp"

class Field : public QGraphicsView {
public:
    explicit Field(QWidget *parent = nullptr);

protected:
     void dragEnterEvent(QDragEnterEvent *event);    
     void dropEvent(QDropEvent *event);

private:
    const int FIELD_SIZE = 50;
    QScopedPointer<BusinessLogicLayer> game_logic;
};

#endif // FIELD_HPP
