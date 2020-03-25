#include "organism.h"

#include <QDebug>

Organism::Organism()
{
}


int Organism::CompareGenomes(Genome &g1, Genome &g2)
{
    int difference = 0;

    char *inc1, *inc2;

    inc1 = (char*)&g1;
    inc2 = (char*)&g2;

    for(int i = 0; i < sizeof(Genome); i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if((bool((1 << j)  &  inc1[i])) != (bool((1 << j)  &  inc2[i])))
            {
                difference++;
            }
        }
    }

    delete inc1;
    delete inc2;

    return difference;
}

void Organism::FillVectorRandomly(QVector<Organism> &vector, int count, Genome &pattern, int range)
{
    Genome gen;
    Organism org;
}
