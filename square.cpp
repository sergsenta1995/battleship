#include "square.hpp"

Square::Square(char letter_, int coord_) :
    letter(letter_),
    coord(coord_)
{}

QRectF Square::boundingRect() const
{    
    return QRectF(0,0, SQUARE_SIZE, SQUARE_SIZE);
}

void Square::paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *item_style,
                   QWidget *widget)
{        
    painter->save();
    painter->setPen(QPen(Qt::black, PEN_SIZE));
    QPointF position(0,0);
    painter->drawRect(QRectF(position, QSize(SQUARE_SIZE, SQUARE_SIZE)));
    painter->restore();
}
