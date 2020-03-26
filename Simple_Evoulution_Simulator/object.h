#ifndef OBJECT_H
#define OBJECT_H


#include <QColor>

enum ObjectType {ORGANISM, PLANT, MEAT};



class Object
{
protected:
    double Energy;
    QColor Color;
    double x, y;
    ObjectType type;
    double Size;

public:
    Object(ObjectType tp) { type = tp; }
    Object();

    //Setters
    void setEnergy        (double value)    { Energy = value; }
    void setColor         (QColor value)    { Color = value; }
    void setXPos          (double value)    { x = value; }
    void setYPos          (double value)    { y = value; }
    void setSize          (double value)    { Size = value; }
    void setObjectType    (ObjectType value){ type = value; }

    //Getters
    double     getEnergy        ()    { return Energy; }
    QColor     getColor         ()    { return Color; }
    double     getXPos          ()    { return x; }
    double     getYPos          ()    { return y; }
    ObjectType getObjectType    ()    { return type; }
    double     getSize          ()    { return Size; }


    virtual ~Object();

};


#endif // OBJECT_H
