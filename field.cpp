#include "field.hpp"
#include <QGraphicsRectItem>


Field::Field(QWidget *parent) :
    QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(parent);

    for (size_t i = 0; i < 10; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            QGraphicsRectItem * rect = new QGraphicsRectItem();
            rect->setRect(FIELD_SIZE * i, FIELD_SIZE * j, FIELD_SIZE, FIELD_SIZE);
            scene->addItem(rect);
        }
    };

    setScene(scene);
    //show();
}
