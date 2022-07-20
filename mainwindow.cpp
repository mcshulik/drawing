#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "rectangle.h"
#include "ellipse.h"
#include "QLayout"

#define mylength 90
#define mywidth 60

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->installEventFilter(this);
    this->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_EllipseButton_clicked()
{
    if(!this->clicked_on_ellipse)
    {
        this->clicked_on_ellipse = true;
        this->clicked_on_rectangle = false;
        this->clicked = false;
        ui->EllipseButton->setStyleSheet("background: rgb(192, 192, 192); color: red;");
        ui->RectangleButton->setStyleSheet("background: rgb(225, 225, 225); color: black;");
    }
    else
    {
        ui->EllipseButton->setStyleSheet("background: rgb(225, 225, 225); color: black;");
        this->clicked_on_ellipse = false;
    }
}

void MainWindow::on_RectangleButton_clicked()
{
    if(!this->clicked_on_rectangle)
    {
        this->clicked_on_rectangle = true;
        this->clicked_on_ellipse = false;
        this->clicked = false;
        ui->RectangleButton->setStyleSheet("background: rgb(192, 192, 192); color: red;");
        ui->EllipseButton->setStyleSheet("background: rgb(225, 225, 225); color: black;");
    }
    else
    {
        ui->RectangleButton->setStyleSheet("background: rgb(225, 225, 225); color: black;");
        this->clicked_on_rectangle = false;
    }
}


void MainWindow::doPainting()
{
    QPainter painter(this);
    QPoint point;
    Rectangle *rectangleObject = new Rectangle();
    Ellipse *ellipseObject = new Ellipse();
    if(this->clicked_on_rectangle && this->clicked == true)
    {
        std::unique_ptr<Shape> ptr(rectangleObject);
        this->objects.push_back(std::move(ptr));
        objects.back().get()->setPos(this->point);
        this->clicked = false;
    }
    else
        if(this->clicked_on_ellipse && this->clicked == true)
        {
            std::unique_ptr<Shape> ptr(ellipseObject);
            this->objects.push_back(std::move(ptr));
            objects.back().get()->setPos(this->point);
            this->clicked = false;
        }
        else
            if(this->clicked)
            {
                for(int i = 0; i < objects.size(); i++)
                {
                    point = QCursor::pos() - this->geometry().topLeft();
                    if(objects[i].get()->isInsideShape(point, this->movable_number))
                    {
                        movable_number = i;
                        break;
                    }
                }
            }
    for(int i = 0; i < objects.size(); i++)
        objects[i]->doPainting(painter, this->objects, this->movable_number, point, i);
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    doPainting();
    this->update();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
    {
        this->clicked = true;
        if(this->clicked_on_rectangle || this->clicked_on_ellipse)
        {
            this->point = QCursor::pos() - this->geometry().topLeft();
        }
        else
        {
            this->movable_number = -1;
        }
    }
    else
        if(event->type() == QEvent::MouseButtonRelease)
        {
            this->movable_number = -2;
        }
    return QWidget::eventFilter(obj, event);
}
