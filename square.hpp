#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneDragDropEvent>

class Square : public QGraphicsItem {    
public:
    explicit Square(char letter, int coord);
    QRectF boundingRect() const override;
    void   paint(QPainter *painter,
                 const QStyleOptionGraphicsItem* item_style,
                 QWidget *widget) override;

private:
    const int SQUARE_SIZE   = 50;
    const int PEN_SIZE      = 2;

    char letter;
    int coord;    
};

#endif // SQUARE_HPP
