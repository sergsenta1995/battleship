#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void clear_field();

private slots:
    void on_clear_field_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAIN_WINDOW_HPP
