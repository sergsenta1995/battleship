#ifndef SHIP_HPP
#define SHIP_HPP

#include <QLabel>

class Ship : public QLabel {
    Q_OBJECT
public:
    explicit Ship(QWidget *parent = nullptr);

protected:
    //! События для обработи Drag and Drop-а.
    void mousePressEvent(QMouseEvent *event) override;

private:
    int number_of_ship;

};

#endif // SHIP_HPP
