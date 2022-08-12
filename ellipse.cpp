#include <QPainter>
#include "ellipse.h"
#include <QCursor>

Ellipse::Ellipse()
{
    this->length = ellipseLength;
    this->width = ellipseWidth;
    this->x = 0;
    this->y = 0;
}

void Ellipse::doPainting(InterfaceForPainting &interfaceForPainting)
{
    if(this->brushColor == color::Color::Empty)
        return;
    interfaceForPainting.setPen();
    interfaceForPainting.setBrush(this->brushColor);
    interfaceForPainting.drawEllipse(this->x, this->y, this->length, this->width);
}

bool Ellipse::isInsideShape (QPoint point)
{
    if ((float)(point.x() - this->x - (float)(this->length / 2)) * (float)(point.x() - this->x - (float)(this->length / 2)) / ((float)(this->length / 2) * (float)(this->length / 2)) +
        (float)(point.y() - this->y - (float)(this->width / 2)) * (float)(point.y() - this->y - (float)(this->width / 2)) / ((float)(this->width / 2) *  (float)(this->width / 2)) <= 1)
            return true;
        else return false;
}

void Ellipse::xmlWrite(QXmlStreamWriter &xmlWriter)
{
    xmlWriter.writeStartElement("ellipse");

    xmlWriter.writeAttribute("length", QString::number(length));
    xmlWriter.writeAttribute("width", QString::number(width));
    xmlWriter.writeAttribute("x", QString::number(x));
    xmlWriter.writeAttribute("y", QString::number(y));
    xmlWriter.writeAttribute("color", QString::number(brushColor));

    xmlWriter.writeEndElement();
}

Shape* Ellipse::xmlRead(QXmlStreamReader &xmlReader)
{
    QXmlStreamAttributes attributes = xmlReader.attributes();
    //attributes.value("length");
    //attributes.value("width");
    Ellipse *ellipse = new Ellipse;
    QPoint ellipse_point;
    ellipse_point.setX(attributes.value("x").toInt());
    ellipse_point.setY(attributes.value("y").toInt());
    ellipse->setColor(color::Color(attributes.value("color").toInt()));
    ellipse->setPos(ellipse_point);
    return ellipse;
}
