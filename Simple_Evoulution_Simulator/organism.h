#ifndef ORGANISM_H
#define ORGANISM_H

#include <QColor>

#include "genom.h"


class Organism
{
private:
    double Energy;
    double Energy_Per_Day;
    double Energy_Per_Attack;
    QColor Color;
    double x, y;
    double rotateAngle;

    Genom genom;

public:
    Organism();

    //static int CompareGenoms(Genom &g1, Genom &g2); //Return the difference between 2 genoms

    //Setters
    void setEnergy        (double &value)    { Energy = value; }
    void setEPD           (double &value)    { Energy_Per_Day = value; } //Energy per day
    void setEPA           (double &value)    { Energy_Per_Attack = value; } //Energy per attack
    void setColor         (QColor &value)    { Color = value; }
    void setGenom         (Genom  &value)    { genom = value; }
    void setXPos          (double &value)    { x = value; }
    void setYPos          (double &value)    { y = value; }
    void setRotateAngle   (double &value)    { rotateAngle = value; }

    //Getters
    double getEnergy        ()    { return Energy; }
    double getEPD           ()    { return Energy_Per_Day; } //Energy per day
    double getEPA           ()    { return Energy_Per_Attack; } //Energy per attack
    QColor getColor         ()    { return Color; }
    Genom  getGenom         ()    { return genom; }
    double getXPos          ()    { return x; }
    double getYPos          ()    { return y; }
    double getRotateAngle   ()    { return rotateAngle; }
};

#endif // ORGANISM_H
