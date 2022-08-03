#ifndef INTERFACEFORPAINTING_H
#define INTERFACEFORPAINTING_H
#include <QBrush>
#include <QColor>

class InterfaceForPainting
{
public:
    virtual void setPen(int color) = 0;
    virtual void setBrush(int color) = 0;
    virtual void drawEllipse(int x, int y, int length, int width) = 0;
    virtual void drawRect(int x, int y, int length, int width) = 0;
};

#endif // INTERFACEFORPAINTING_H
