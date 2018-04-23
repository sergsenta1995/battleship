#include "field.hpp"
#include "square.hpp"

#include <QMimeData>
#include <QGraphicsRectItem>

Field::Field(QWidget *parent) :
    QGraphicsView(parent)
{    
    const int field_dimension = 10;
    char letters[field_dimension] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};

    QGraphicsScene *scene = new QGraphicsScene();

    for (size_t i = 0; i < 10; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            Square *s = new Square(letters[i], j);
            s->setPos(FIELD_SIZE * i, FIELD_SIZE * j);
            s->setAcceptDrops(true);
            scene->addItem(s);
        }
    };

    setScene(scene);
    show();

    //setAcceptDrops(true);
}


void Field::dragEnterEvent(QDragEnterEvent *event)
{
    QGraphicsView::dragEnterEvent(event);
    event->accept();
}

void Field::dropEvent(QDropEvent *event)
{    
    QPixmap img = qvariant_cast<QPixmap>(event->mimeData()->imageData());

    QByteArray item_data = event->mimeData()->data("application/x-dnditemdata");
    QDataStream dataStream(&item_data, QIODevice::ReadOnly);
    QPoint offset;
    dataStream >> offset;

    int actual_x = event->pos().x() - offset.x();
    int actual_y = event->pos().y() - offset.y();
    QRect drag_image_rect(actual_x, actual_y, img.width(), img.height());

    // Когда перетаскиваемый корбль сильно вылазиет за границу.
    if (drag_image_rect.x() < -(FIELD_SIZE / 2) || drag_image_rect.y() < -(FIELD_SIZE / 2))
        return;

    foreach (QGraphicsItem *i, scene()->items(Qt::AscendingOrder))
    {
        QRectF item_bounding_rect = i->sceneBoundingRect();
        QRectF intersection_rect = item_bounding_rect & drag_image_rect;

        if (intersection_rect.isEmpty())
            continue;

        // Идея: при пересечении с центром кварата - фигура  к этому квадрату.
        if (intersection_rect.contains(item_bounding_rect.center()))
        {
            QGraphicsPixmapItem *temp_pix_item = new QGraphicsPixmapItem(img);
            temp_pix_item->setPos(i->pos());                        
            this->scene()->addItem(temp_pix_item);
            return;
        }
    }

    QGraphicsView::dropEvent(event);
}

