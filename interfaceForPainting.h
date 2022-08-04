#ifndef INTERFACEFORPAINTING_H
#define INTERFACEFORPAINTING_H
#include <QBrush>
#include <QColor>

namespace color
{
    enum Color
    {
        Empty = -1,
        Blue,
        Green,
        Red,
        Brown,
        Grey,
        count
    };
    inline  const char* convertColorToString(Color color)
    {
        switch(color)
        {
            case Blue:
                return "Blue";
                break;
            case Green:
                return "Green";
                break;
            case Red:
                return "Red";
                break;
            case Brown:
                return "Brown";
                break;
            case Grey:
                return "Grey";
                break;
            default:
                return "Empty";
                break;
        }
    }
}

class InterfaceForPainting
{
public:
    virtual void setPen() = 0;
    virtual void setBrush(color::Color) = 0;
    virtual void drawEllipse(int x, int y, int length, int width) = 0;
    virtual void drawRect(int x, int y, int length, int width) = 0;
};

#endif // INTERFACEFORPAINTING_H
