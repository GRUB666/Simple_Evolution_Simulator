#include "organism.h"

#include <QDebug>

Organism::Organism() : Object(ObjectType::ORGANISM)
{
    setSize(genome.getSize());
}

int Organism::CompareGenomes(const Genome &g1, const Genome &g2)
{
    int difference = 0;

    const uint8_t *inc1 = reinterpret_cast<const uint8_t *>(&g1);
    const uint8_t *inc2 = reinterpret_cast<const uint8_t *>(&g2);

    for (int i = 0; i < sizeof(Genome); ++i)
        for (uint8_t dx = inc1[i] ^ inc2[i]; dx; dx >>= 1)
            if (dx & 0x01)
                ++difference;
    return difference;
}

void Organism::FillVectorRandomly(QVector<Organism> &vector, int count, Genome &pattern, int range)
{
    Genome gen;
    Organism org;
}

bool Organism::isFriend(Organism &actor, Organism &target)
{
    return CompareGenomes(actor.getGenome(), target.getGenome()) <= actor.getGenome().getDifferenceMaxLevel();
}

double Organism::getTrggerForce(Object &obj, double distance)
{
    switch (obj.getObjectType())
    {
    case ObjectType::PLANT:
        return 10 * genome.getPlant_k() / distance;
        break;

    case ObjectType::MEAT:
        return 10 * genome.getMeat_k() / distance;
        break;

    case ObjectType::ORGANISM:
        Organism* org = dynamic_cast<Organism* >(&obj);

        if(isFriend(*this, *org))
            return 10 * genome.getFriendly_Organism_k() / distance;
        else
            return 10 * genome.getAilen_Organism_k() / distance;
        break;
    }

    return 0;
}

bool Organism::canBeAlive()
{
    return Energy > 0;
}

//TODO:
void Organism::wasteEnergy()
{

}

void Organism::Move()
{
    x += genome.getSpeed() * cos(rotateAngle);
    y += genome.getSpeed() * sin(rotateAngle);
}
