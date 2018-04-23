#include "ship.hpp"
#include <QMouseEvent>
#include <QMimeData>
#include <QDrag>

Ship::Ship(QWidget *parent) :
    QLabel(parent)
{}

void Ship::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        QPixmap pixmap = *this->pixmap();
        pixmap = pixmap.scaled(this->maximumSize());


        QByteArray item_data;
        QDataStream data_stream(&item_data, QIODevice::WriteOnly);
        data_stream << QPoint(event->pos());

        QMimeData *mime_data = new QMimeData;
        mime_data->setImageData(pixmap);
        mime_data->setData("application/x-dnditemdata", item_data);

        QDrag *drag = new QDrag(this);
        drag->setMimeData(mime_data);
        drag->setPixmap(pixmap);
        drag->setHotSpot(event->pos());

        drag->start();
    }

    QLabel::mousePressEvent(event);
}
