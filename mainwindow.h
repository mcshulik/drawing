#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shape.h"
#include "QComboBox"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QPushButton;
QT_END_NAMESPACE

class Factory;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool eventFilter(QObject *obj, QEvent *event);
    void doPainting();
    Shape* createShape();

private slots:
    void buttonClicked();

private:
    void paintEvent(QPaintEvent *e);
    Ui::MainWindow *ui;
    bool clicked = false;
    std::vector<std::unique_ptr<Shape>> objects;
    int movable_number = -1;
    QComboBox *colorButton;
    std::map<QPushButton*, std::pair<bool, Factory*>> mybuttonsClicked;
    std::vector<QPushButton*> mybuttons;
};
#endif // MAINWINDOW_H
