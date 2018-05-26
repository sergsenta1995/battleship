#include "main-window.hpp"
#include "ui_main-window.h"

#include "business-logic-layer.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
