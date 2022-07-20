#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shape.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *obj, QEvent *event);
    void doPainting();

private slots:
    void on_EllipseButton_clicked();
    void on_RectangleButton_clicked();

private:
    void paintEvent(QPaintEvent *e);
    Ui::MainWindow *ui;
    bool clicked = false, clicked_on_rectangle = false, clicked_on_ellipse = false, move = false;
    QPoint point;
    std::vector<std::unique_ptr<Shape>> objects;
    int movable_number = -1;
};
#endif // MAINWINDOW_H
