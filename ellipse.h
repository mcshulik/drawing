#ifndef ELLIPSE_H
#define ELLIPSE_H

#define ellipseLength 90
#define ellipseWidth 60

#include "shape.h"
#include "qPainterAdapter.h"

class Ellipse : public Shape
{

  public:
    Ellipse();
    ~Ellipse() {};
    void doPainting(InterfaceForPainting &interfaceForPainting) override;
    bool isInsideShape (QPoint point) override;
    void xmlWrite(QXmlStreamWriter &xmlWriter) override;
    static Shape* xmlRead(QXmlStreamReader &xmlReader);
  private:
    int length = ellipseLength, width = ellipseWidth;
};

#endif // ELLIPSE_H
