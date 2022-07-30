#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "rectangle.h"
#include "ellipse.h"
#include "QLayout"
#include "factorySingleton.h"

#define mylength 90
#define mywidth 60

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->centralwidget->installEventFilter(this);
    QWidget * wdg = new QWidget(this);
    for(int i = 0; i < (FactorySingleton::getInstance())->getVect()->size(); i++)
    {
        Factory* factory = (*(FactorySingleton::getInstance())->getVect())[i].get();
        QPushButton* mybutton = new QPushButton(factory->getName(), wdg);
        mybutton->resize(101, 41);
        mybutton->move(i * 140 + 260, 40);
        mybutton->setFont(QFont("Segoe UI", 9, QFont::Normal));
        QObject::connect(mybutton, SIGNAL(clicked()), this, SLOT(buttonClicked()));
        mybuttons.push_back(mybutton);
        mybuttonsClicked[mybutton] = std::pair<bool, Factory*>(false, factory);
        mybutton->show();
    }
    wdg->installEventFilter(this);
    setCentralWidget(wdg);
    this->repaint();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::buttonClicked()
{
    auto button = (QPushButton*)this->sender();
    if(!this->mybuttonsClicked[button].first)
    {
        this->mybuttonsClicked[button].first = true;
        for(auto &pair : this->mybuttonsClicked)
        {
            if(pair.first != button)
            {
                pair.second.first = false;
                pair.first->setStyleSheet("background: rgb(225, 225, 225); color: black;");
            }
        }
        this->clicked = false;
        button->setStyleSheet("background: rgb(192, 192, 192); color: red;");
    }
    else
    {
        button->setStyleSheet("background: rgb(225, 225, 225); color: black;");
        this->mybuttonsClicked[button].first = false;
    }
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
    if(this->movable_number > -1)
        objects[this->movable_number]->setPos(QCursor::pos() - this->geometry().topLeft());
    QPainter painter(this);
    for(int i = 0; i < objects.size(); i++)
        objects[i]->doPainting(painter);
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
        for (const std::pair<QPushButton*, std::pair<bool, Factory*>>&pairItem : mybuttonsClicked)
        {
            if (pairItem.second.first)
            {
                std::unique_ptr<Shape> ptr = std::unique_ptr<Shape>(pairItem.second.second->createShape());
                this->objects.push_back(std::move(ptr));
                objects.back().get()->setPos(QCursor::pos() - this->geometry().topLeft());
                this->clicked = false;
                return QWidget::eventFilter(obj, event);
            }
        }
        for(int i = 0; i < objects.size(); i++)
        {
            if(objects[i].get()->isInsideShape(QCursor::pos() - this->geometry().topLeft()))
            {
                movable_number = i;
                break;
            }
        }
        /*if(this->clicked_on_rectangle)
        {
            std::unique_ptr<Shape> ptr = std::make_unique<Rectangle>();
            this->objects.push_back(std::move(ptr));
            objects.back().get()->setPos(QCursor::pos() - this->geometry().topLeft());
            this->clicked = false;
        }
        else if(this->clicked_on_ellipse)
        {
            std::unique_ptr<Shape> ptr = std::make_unique<Ellipse>();
            this->objects.push_back(std::move(ptr));
            objects.back().get()->setPos(QCursor::pos() - this->geometry().topLeft());
            this->clicked = false;
        }
        else
        {
            for(int i = 0; i < objects.size(); i++)
            {
                if(objects[i].get()->isInsideShape(QCursor::pos() - this->geometry().topLeft()))
                {
                    movable_number = i;
                    break;
                }
            }
        }*/
    }
    else if(event->type() == QEvent::MouseButtonRelease)
    {
        this->movable_number = -1;
    }
    return QWidget::eventFilter(obj, event);
}
