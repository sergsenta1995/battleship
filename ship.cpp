#include "ship.hpp"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>

#include <QDebug>

Ship::Ship(QWidget *parent) :
    QLabel(parent)
{

}

void Ship::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPixmap pixmap = *this->pixmap();
        pixmap = pixmap.scaled(this->maximumSize());

        QByteArray itemData;
        QDataStream dataStream(&itemData, QIODevice::WriteOnly);
        dataStream << pixmap << QPoint(event->pos());

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("application/x-dnditemdata", itemData);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->setPixmap(pixmap);
        drag->setHotSpot(event->pos());


        if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
        {
            this->close();
        }
    }
}
