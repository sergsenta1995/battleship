#include "main-window.hpp"
#include "ui_main-window.h"

#include "business-logic-layer.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ui->ship_2_label->setGeometry(0,0,50,100);

    connect(this,
            &MainWindow::clear_field,
            ui->field_1_graphicsView,
            &Field::clear);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clear_field_pushButton_clicked()
{
    emit clear_field();
}

void MainWindow::on_rotate_1_desk_ship_pushButton_clicked()
{
    QPixmap pix_temp(ui->ship_1_label->pixmap()->copy());
    QMatrix rm;
    rm.rotate(-90);
    pix_temp = pix_temp.transformed(rm);

    ui->ship_1_label->setMaximumSize(ui->ship_1_label->maximumHeight(), ui->ship_1_label->maximumWidth());
    ui->ship_1_label->setPixmap(pix_temp);

}

void MainWindow::on_rotate_2_desk_ship_pushButton_clicked()
{
    QPixmap pix_temp(ui->ship_2_label->pixmap()->copy());
    pix_temp.size();
    QMatrix rm;
    rm.rotate(-90);
    pix_temp = pix_temp.transformed(rm);

    ui->ship_2_label->setMaximumSize(ui->ship_2_label->maximumHeight(), ui->ship_2_label->maximumWidth());
    ui->ship_2_label->setPixmap(pix_temp);
}

void MainWindow::on_rotate_3_desk_ship_pushButton_clicked()
{
    QPixmap pix_temp(ui->ship_3_label->pixmap()->copy());
    QMatrix rm;
    rm.rotate(-90);
    pix_temp = pix_temp.transformed(rm);

    ui->ship_3_label->setMaximumSize(ui->ship_3_label->maximumHeight(), ui->ship_3_label->maximumWidth());
    ui->ship_3_label->setPixmap(pix_temp);
}

void MainWindow::on_rotate_4_desk_ship_pushButton_clicked()
{
    QPixmap pix_temp(ui->ship_4_label->pixmap()->copy());
    QMatrix rm;
    rm.rotate(-90);
    pix_temp = pix_temp.transformed(rm);

    ui->ship_4_label->setMaximumSize(ui->ship_4_label->maximumHeight(), ui->ship_4_label->maximumWidth());
    ui->ship_4_label->setPixmap(pix_temp);
}
