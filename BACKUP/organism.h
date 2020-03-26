#ifndef ORGANISM_H
#define ORGANISM_H

#include "genom.h"
#include "object.h"




class Organism : public Object
{
private:
    double Energy_Per_Day;
    double Energy_Per_Attack;
    double rotateAngle;

    Genome genome;

public:
    Organism();

    static int CompareGenomes(const Genome &g1, const Genome &g2); //Return the difference between 2 genoms
    static void FillVectorRandomly(QVector<Organism> &vector, int count, Genome &pattern, int range = 0);
    static bool isFriend(Organism &actor, Organism &target);

    double getTrggerForce(Object& obj, double distance);

    bool canBeAlive();

    void wasteEnergy();

    void Move();

    //Setters
    void setEPD           (double value)    { Energy_Per_Day = value; } //Energy per day
    void setEPA           (double value)    { Energy_Per_Attack = value; } //Energy per attack
    void setGenome        (Genome  &value)  { static_cast<void>(genome = value), Size = genome.getSize(); }
    void setRotateAngle   (double value)    { rotateAngle = value; }

    //Getters
    double getEPD           ()    { return Energy_Per_Day; } //Energy per day
    double getEPA           ()    { return Energy_Per_Attack; } //Energy per attack  
    Genome getGenome        ()    { return genome; }
    double getRotateAngle   ()    { return rotateAngle; }
};


enum TriggerType {VOID_T, FRIEND_T, AILEN_T, PLANT_T, MEAT_T};

struct Trigger
{
    Trigger()
    {
        type = TriggerType::VOID_T;
        triggerForce = 0;
    }

    void setTriggerTypeWithObject(Object &actor, Object &target)
    {
        switch (target.getObjectType())
        {
        case ObjectType::PLANT:
            type = TriggerType::PLANT_T;
        case ObjectType::MEAT:
            type = TriggerType::MEAT_T;
        case ObjectType::ORGANISM:
            Organism *pAct = dynamic_cast<Organism* >(&actor);
            Organism *pTarg = dynamic_cast<Organism* >(&target);

            if(Organism::isFriend(*pAct, *pTarg))
                type = TriggerType::FRIEND_T;
            else
                type = TriggerType::AILEN_T;

            break;
        }
    }

    double triggerForce;
    TriggerType type;
};



#endif // ORGANISM_H
