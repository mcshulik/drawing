#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shape.h"
#include "QComboBox"
#include <QShortcut>
#include "QFile"

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

private slots:
    void buttonClicked();
    void slotShortcutCtrlS();
    void slotShortcutCtrlL();

private:
    void paintEvent(QPaintEvent *e);
    void load();
    void save();
    bool eventFilter(QObject *obj, QEvent *event);
    void doPainting();
    Shape* createShape();

private:
    Ui::MainWindow *ui;
    bool clicked = false;
    std::vector<std::unique_ptr<Shape>> objects;
    int movable_number = -1;
    QComboBox *colorButton;
    std::map<QPushButton*, std::pair<bool, Factory*>> mybuttonsClicked;
    std::vector<QPushButton*> mybuttons;
    QShortcut *keyCtrlS;
    QShortcut *keyCtrlL;
    QFile *file;
};
#endif // MAINWINDOW_H
