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

    Genome genom;

public:
    Organism();

    static int CompareGenomes(Genome &g1, Genome &g2); //Return the difference between 2 genoms
    static void FillVectorRandomly(QVector<Organism> &vector, int count, Genome &pattern, int range = 0);


    //Setters
    void setEnergy        (double value)    { Energy = value; }
    void setEPD           (double value)    { Energy_Per_Day = value; } //Energy per day
    void setEPA           (double value)    { Energy_Per_Attack = value; } //Energy per attack
    void setColor         (QColor value)    { Color = value; }
    void setGenome         (Genome  &value)   { genom = value; }
    void setXPos          (double value)    { x = value; }
    void setYPos          (double value)    { y = value; }
    void setRotateAngle   (double value)    { rotateAngle = value; }

    //Getters
    double getEnergy        ()    { return Energy; }
    double getEPD           ()    { return Energy_Per_Day; } //Energy per day
    double getEPA           ()    { return Energy_Per_Attack; } //Energy per attack
    QColor getColor         ()    { return Color; }
    Genome  getGenome         ()    { return genom; }
    double getXPos          ()    { return x; }
    double getYPos          ()    { return y; }
    double getRotateAngle   ()    { return rotateAngle; }
};

#endif // ORGANISM_H
