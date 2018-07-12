#include "field.hpp"
#include "square.hpp"

#include <QMimeData>
#include <QGraphicsRectItem>
#include <QtGlobal>

Field::Field(QWidget *parent) :
    QGraphicsView(parent),
    game_logic(new BusinessLogicLayer()),
    ships_group(new QGraphicsItemGroup())
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

    scene->addItem(ships_group);

    setScene(scene);
    show();
}


void Field::dragEnterEvent(QDragEnterEvent *event)
{
    QGraphicsView::dragEnterEvent(event);
    event->accept();
}

void Field::dropEvent(QDropEvent *event)
{    
    QPixmap ship_image = qvariant_cast<QPixmap>(event->mimeData()->imageData());

    // Извлекаем смещение относительно позиции курсора, за которую схватили корабль.
    QByteArray item_data = event->mimeData()->data("application/x-dnditemdata");
    QDataStream temp_data_stream(&item_data, QIODevice::ReadOnly);
    QPoint cursor_offset;
    temp_data_stream >> cursor_offset;

    int left_upper_x = event->pos().x() - cursor_offset.x();
    int left_upper_y = event->pos().y() - cursor_offset.y();
    QRect drag_image_rect(left_upper_x, left_upper_y, ship_image.width(), ship_image.height());

    int number_of_decks = qMax(ship_image.width() / 50, ship_image.height() / 50);

    // Когда перетаскиваемый корбль сильно вылезает за границу.
    if (drag_image_rect.x() < -(FIELD_SIZE / 2) || drag_image_rect.y() < -(FIELD_SIZE / 2) ||
        drag_image_rect.x() > (FIELD_SIZE / 2) || drag_image_rect.y() > (FIELD_SIZE / 2))
    {
        return;
    }

    // Определяем куда сброшен корабль.
    foreach (QGraphicsItem *i, scene()->items(Qt::AscendingOrder))
    {
        QRectF item_bounding_rect = i->sceneBoundingRect();
        QRectF intersection_rect = item_bounding_rect & drag_image_rect;

        if (intersection_rect.isEmpty())
            continue;

        // Если перетаскиваемый корабль пересекает центр поля, то он устанавливается в это поле.
        if (intersection_rect.contains(item_bounding_rect.center()))
        {
            QGraphicsPixmapItem *dropped_pix = new QGraphicsPixmapItem(ship_image);
            dropped_pix->setPos(i->pos());

            // Определяем поля в которые попадает корабль.
            QPoint ship_begin_point(i->pos().x() / FIELD_SIZE, i->pos().y() / FIELD_SIZE);
            int ship_end_point_x = (i->pos().x() + drag_image_rect.width()) / FIELD_SIZE;
            int ship_end_point_y = (i->pos().y() + drag_image_rect.height()) / FIELD_SIZE;
            QPoint ship_end_point(ship_end_point_x, ship_end_point_y);

            // Если еще не разместили все корабли и
            // корабль попадает в корректные поля
            if (number_of_ship[number_of_decks - 1] > 0 &&
                game_logic->place_ship(ship_begin_point, ship_end_point) == true)
            {
                --number_of_ship[number_of_decks - 1];
                ships_group->addToGroup(dropped_pix);
            }
            else
                qDebug() << "no";

            return;
        }
    }

    QGraphicsView::dropEvent(event);
}

void Field::clear()
{
    //scene()->removeItem(ships_group);
    foreach( QGraphicsItem *item, scene()->items(ships_group->boundingRect())) {
       if(item->group() == ships_group ) {
          scene()->removeItem(item);
       }
    }

    game_logic->clear();
}
