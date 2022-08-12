#include <QPainter>
#include "rectangle.h"
#include <QCursor>

Rectangle::Rectangle()
{
    this->length = rectLength;
    this->width = rectWidth;
    this->x = 0;
    this->y = 0;
}

void Rectangle::doPainting(InterfaceForPainting &interfaceForPainting)
{    
    if(this->brushColor == color::Color::Empty)
        return;
    interfaceForPainting.setPen();
    interfaceForPainting.setBrush(this->brushColor);
    interfaceForPainting.drawRect(this->x, this->y, this->length, this->width);
}

bool Rectangle::isInsideShape (QPoint point)
{
    return this->x <= point.x() && this->x + this->length >= point.x() && this->y <= point.y() && this->y + this->width >= point.y();
}

void Rectangle::xmlWrite(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("rectangle");

    xmlWriter.writeStartElement("length");
    xmlWriter.writeCharacters(QString::number(length));
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement("width");
    xmlWriter.writeCharacters(QString::number(width));
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement("x");
    xmlWriter.writeCharacters(QString::number(x));
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement("y");
    xmlWriter.writeCharacters(QString::number(y));
    xmlWriter.writeEndElement();
    xmlWriter.writeStartElement("color");
    xmlWriter.writeCharacters(QString::number(brushColor));
    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();
}

Shape* Rectangle::xmlRead(QXmlStreamReader &xmlReader)
{
    Rectangle *rect = new Rectangle;
    for(int i = 0; i < 3; i++)
        xmlReader.readNext();
    //int length = xmlReader.text().toInt();
    for(int i = 0; i < 4; i++)
        xmlReader.readNext();
    //int width = xmlReader.text().toInt();
    for(int i = 0; i < 4; i++)
        xmlReader.readNext();
    QPoint rect_point;
    rect_point.setX(xmlReader.text().toInt());
    for(int i = 0; i < 4; i++)
        xmlReader.readNext();
    rect_point.setY(xmlReader.text().toInt());
    for(int i = 0; i < 4; i++)
        xmlReader.readNext();
    rect->setColor(color::Color(xmlReader.text().toInt()));
    rect->setPos(rect_point);
    return rect;
}
