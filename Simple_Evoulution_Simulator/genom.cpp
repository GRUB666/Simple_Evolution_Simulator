#include "genom.h"

Genome::Genome()
{

}

double getMutatedValue(double origin_value, double value_of_mutation, double proballity)
{
    if(FlipDice(proballity))
    {
        if(FlipDice(0.5)) //Positive change
            origin_value *= (1 + value_of_mutation);

        else //Negative change
            origin_value *= (1 - value_of_mutation);
    }

    return origin_value;
}


int getCountOfCommands()
{
    int count = 0;

    while(count != Command::_TENAC)
        count++;

    return count;
}

Command getMutatedCommand(Command original_command, double proballity)
{
    if(FlipDice(proballity))
    {
        int cm_count = getCountOfCommands();
        Command new_command = Command(getValueFromDiapasone(0, cm_count - 1));

        while(new_command == original_command)
             new_command = Command(getValueFromDiapasone(0, cm_count - 1));

        original_command = new_command;
    }

    return original_command;
}


Genome Genome::getGenomeOfChild()
{
    Genome new_genome;

    //-----Mutation---------------
    new_genome.setLifeLimit(getMutatedValue(this->getLifeLimit(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setReproductionDownLevel(getMutatedValue(this->getReproductionDownLevel(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setAttackForce(getMutatedValue(this->getAttackForce(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setSpeed(getMutatedValue(this->getSpeed(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setVisionRadius(getMutatedValue(this->getVisionRadius(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setSize(getMutatedValue(this->getSize(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setAttackRadius(getMutatedValue(this->getAttackRadius(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setDifferenceMaxLevel(getMutatedValue(this->getDifferenceMaxLevel(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setPlant_k(getMutatedValue(this->getPlant_k(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setMeat_k(getMutatedValue(this->getMeat_k(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setAilen_Organism_k(getMutatedValue(this->getAilen_Organism_k(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setFriendly_Organism_k(getMutatedValue(this->getFriendly_Organism_k(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setProbability_of_mutation(getMutatedValue(this->getProbability_of_mutation(), this->Value_of_mutation, this->Probability_of_mutation));
    new_genome.setValue_of_mutation(getMutatedValue(this->getValue_of_mutation(), this->Value_of_mutation, this->Probability_of_mutation));

    new_genome.setPlant_command(getMutatedCommand(this->getPlant_command(), this->Probability_of_mutation));
    new_genome.setMeat_command(getMutatedCommand(this->getMeat_command(), this->Probability_of_mutation));
    new_genome.setEmpty_zone_command(getMutatedCommand(this->getEmpty_zone_command(), this->Probability_of_mutation));
    new_genome.setAilen_command(getMutatedCommand(this->getAilen_command(), this->Probability_of_mutation));
    new_genome.setFriend_command(getMutatedCommand(this->getFriend_command(), this->Probability_of_mutation));
    new_genome.setBeen_attacked_command(getMutatedCommand(this->getBeen_attacked_command(), this->Probability_of_mutation));
    //-----Mutation---------------

    return new_genome;
}


