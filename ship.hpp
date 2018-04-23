#ifndef SHIP_HPP
#define SHIP_HPP

#include <QLabel>

class Ship : public QLabel {
public:
    explicit Ship(QWidget *parent = nullptr);

protected:
    //! События для обработи Drag and Drop-а.
    void mousePressEvent(QMouseEvent *event) override;

private:

};

#endif // SHIP_HPP
