#ifndef FIELD_HPP
#define FIELD_HPP

#include <QGraphicsView>
#include <QDragEnterEvent>
#include <QDropEvent>

class Field : public QGraphicsView {
public:
    explicit Field(QWidget *parent = nullptr);

protected:
     void dragEnterEvent(QDragEnterEvent *event);    
     void dropEvent(QDropEvent *event);

private:
    const int FIELD_SIZE = 50;
};

#endif // FIELD_HPP
