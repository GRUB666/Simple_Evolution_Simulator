#ifndef GENOM_H
#define GENOM_H

#include "additional_stuff.h"


enum Command {STAY, RANDOM_DIRECTION, GO_FORWARD, ESCAPE, ATTACK,    _TENAC}; /*_TENAC (The End: Not A Command) - a control value that specifies
at the end of the enum*/

class Genome
{
private:

    int Life_limit;
    double Reproduction_down_level; //The start level of reproducton
    double Attack_force;
    double Speed;
    double Vision_radius;
    double Size;
    double Attack_radius;
    double Difference_max_level;
    double Plant_k;
    double Meat_k;
    double Ailen_Organism_k;
    double Friendly_Organism_k;
    double Probability_of_mutation;
    double Value_of_mutation;

    Command Plant_command;
    Command Meat_command;
    Command Empty_zone_command;
    Command Ailen_command;
    Command Friend_command;
    Command Been_attacked_command;


public:
    Genome();

    Genome getGenomeOfChild();

    //Setters
    void setLifeLimit               (int     value)  { Life_limit = value; }
    void setReproductionDownLevel   (double  value)  { Reproduction_down_level = value; }
    void setAttackForce             (double  value)  { Attack_force = value; }
    void setSpeed                   (double  value)  { Speed = value; }
    void setVisionRadius            (double  value)  { Vision_radius = value; }
    void setSize                    (double  value)  { Size = value; }
    void setAttackRadius            (double  value)  { Attack_radius = value; }
    void setDifferenceMaxLevel      (double  value)  { Difference_max_level = value; }
    void setPlant_k                 (double  value)  { Plant_k = value; }
    void setMeat_k                  (double  value)  { Meat_k = value; }
    void setAilen_Organism_k        (double  value)  { Ailen_Organism_k = value; }
    void setFriendly_Organism_k     (double  value)  { Friendly_Organism_k = value; }
    void setProbability_of_mutation (double  value)  { Probability_of_mutation = value; }
    void setValue_of_mutation       (double  value)  { Value_of_mutation = value; }
    void setPlant_command           (Command value) { Plant_command = value; }
    void setMeat_command            (Command value) { Meat_command = value; }
    void setEmpty_zone_command      (Command value) { Empty_zone_command = value; }
    void setAilen_command           (Command value) { Ailen_command = value; }
    void setFriend_command          (Command value) { Friend_command = value; }
    void setBeen_attacked_command   (Command value) { Been_attacked_command = value; }


    //Getters
    int     getLifeLimit                ()  { return Life_limit; }
    double  getReproductionDownLevel    ()  { return Reproduction_down_level; }
    double  getAttackForce              ()  { return Attack_force; }
    double  getSpeed                    ()  { return Speed; }
    double  getVisionRadius             ()  { return Vision_radius; }
    double  getSize                     ()  { return Size; }
    double  getAttackRadius             ()  { return Attack_radius; }
    double  getDifferenceMaxLevel       ()  { return Difference_max_level; }
    double  getPlant_k                  ()  { return Plant_k; }
    double  getMeat_k                   ()  { return Meat_k; }
    double  getAilen_Organism_k         ()  { return Ailen_Organism_k; }
    double  getFriendly_Organism_k      ()  { return Friendly_Organism_k; }
    double  getProbability_of_mutation  ()  { return Probability_of_mutation; }
    double  getValue_of_mutation        ()  { return Value_of_mutation; }
    Command getPlant_command            ()  { return Plant_command; }
    Command getMeat_command             ()  { return Meat_command; }
    Command getEmpty_zone_command       ()  { return Empty_zone_command; }
    Command getAilen_command            ()  { return Ailen_command; }
    Command getFriend_command           ()  { return Friend_command; }
    Command getBeen_attacked_command    ()  { return Been_attacked_command; }
};


#endif // GENOM_H
