#ifndef FIELD_HPP
#define FIELD_HPP

#include <QGraphicsView>

class Field : public QGraphicsView {
public:
    explicit Field(QWidget *parent = nullptr);

private:
    const int FIELD_SIZE = 50;
};

#endif // FIELD_HPP
