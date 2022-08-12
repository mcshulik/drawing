#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "rectangle.h"
#include "ellipse.h"
#include "QLayout"
#include "factorySingleton.h"
#include "qPainterAdapter.h"
#include "QFileDialog"
#include <QXmlStreamWriter>
#include "QFileDialog"

#define mylength 90
#define mywidth 60

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QWidget * wdg = new QWidget(this);

    this->colorButton = new QComboBox(wdg);
    colorButton->resize(101, 41);
    colorButton->move(20, 20);
    colorButton->setFont(QFont("Segoe UI", 9, QFont::Normal));
    colorButton->setPlaceholderText("color");
    for(int i  = 0; i < color::Color::count; i++)
        colorButton->addItem(color::convertColorToString((color::Color)i));
    colorButton->setCurrentIndex(0);
    colorButton->show();
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

    keyCtrlS = new QShortcut(this);
    keyCtrlS->setKey(Qt::CTRL | Qt::Key_S);
    connect(keyCtrlS, SIGNAL(activated()), this, SLOT(slotShortcutCtrlS()));
    keyCtrlL = new QShortcut(this);
    keyCtrlL->setKey(Qt::CTRL | Qt::Key_L);
    connect(keyCtrlL, SIGNAL(activated()), this, SLOT(slotShortcutCtrlL()));

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

void MainWindow::doPainting()
{
    if(this->movable_number > -1)
        objects[this->movable_number]->setPos(QCursor::pos() - this->geometry().topLeft());
    QPainterAdapter qPainterAdapter(this);
    for(int i = 0; i < objects.size(); i++)
        objects[i]->doPainting(qPainterAdapter);
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
                int count = objects.size();
                ptr->setPosChangedListener([&count](QPoint qpoint){printf("%d %d %d\n", qpoint.x(), qpoint.y(), count);});
                this->objects.push_back(std::move(ptr));
                this->objects.back()->setColor((color::Color)this->colorButton->currentIndex());
                objects.back().get()->setPos(QCursor::pos() - this->geometry().topLeft());
                this->clicked = false;
                return QWidget::eventFilter(obj, event);
            }
        }
        for(int i = objects.size() - 1; i > -1; i--)
        {
            if(objects[i].get()->isInsideShape(QCursor::pos() - this->geometry().topLeft()))
            {
                movable_number = i;
                break;
            }
        }
    }
    else if(event->type() == QEvent::MouseButtonRelease)
    {
        this->movable_number = -1;
    }
    return QWidget::eventFilter(obj, event);
}

void MainWindow::slotShortcutCtrlS()
{
    save();
}

void MainWindow::save()
{
    QString filePath = QFileDialog::getSaveFileName();
    file = new QFile(filePath);
    if(!file->open(QIODevice::WriteOnly))
        return;
    if(objects.size())
    {
        QXmlStreamWriter xmlWriter(file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("canvas");
        for(int i = 0; i < objects.size(); i++)
            objects[i].get()->xmlWrite(xmlWriter);
        xmlWriter.writeEndElement();
        xmlWriter.writeEndDocument();
    }
    file->close();
}

void MainWindow::load()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open XML"), "/home/jana", tr("XML Files (*.xml)"));
    file = new QFile(filePath);
    if (!file->open(QFile::ReadOnly | QFile::Text))
    {
        return;
    }
    else
    {
        QXmlStreamReader xmlReader;
        xmlReader.setDevice(file);
        xmlReader.readNext();
        std::string str_ellipse = "ellipse";
        std::string str_rect = "rectangle";
        while(!xmlReader.atEnd())
        {
            if(xmlReader.isStartElement())
            {
                if(xmlReader.name() == QString::fromStdString(str_ellipse))
                {
                    std::unique_ptr<Shape> ptr = std::unique_ptr<Shape>(Ellipse::xmlRead(xmlReader));
                    this->objects.push_back(std::move(ptr));
                }
                else if(xmlReader.name() == QString::fromStdString(str_rect))
                {
                    std::unique_ptr<Shape> ptr = std::unique_ptr<Shape>(Rectangle::xmlRead(xmlReader));
                    this->objects.push_back(std::move(ptr));
                }
            }
            xmlReader.readNext();
        }
        file->close();
    }
    this->doPainting();
}

void MainWindow::slotShortcutCtrlL()
{
    load();
}
