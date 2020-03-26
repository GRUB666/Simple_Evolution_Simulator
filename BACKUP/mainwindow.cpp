#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->viewport->setPointerToPaintVector(&Objects);

    timer = new QTimer(this);
    timer->setInterval(0);
    timer->start();
    connect(timer, SIGNAL(timeout()), this, SLOT(everyTickSlot()));
}


void MainWindow::everyTickSlot()
{
    ui->viewport->update();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::EvolutionCalc()
{
    Object *target_object;
    Trigger strongest_trigger;

    for(auto &var : Objects)
    {
        target_object = nullptr;
        strongest_trigger = Trigger();

        //Acting
        if(var.getObjectType() == ObjectType::ORGANISM)
        {
            Organism &actor = *dynamic_cast<Organism*>(&var);

            if(actor.getEnergy() >= actor.getGenome().getReproductionDownLevel())
            {
                Organism child;
                child = actor;
                Genome new_genome = actor.getGenome().getGenomeOfChild();
                child.setGenome(new_genome);

                double need_dist = actor.getSize() + child.getSize() + 5;

                child.setXPos(child.getXPos() + need_dist*cos(child.getRotateAngle()));
                child.setXPos(child.getXPos() + need_dist*sin(child.getRotateAngle()));

                Objects.push_front(child);
            }

            else
            {
                for(auto &target : Objects)
                {
                    if(getDistance(actor, target) <= actor.getGenome().getVisionRadius())
                    {
                        double distance = getDistance(actor, target) <= actor.getGenome().getVisionRadius();
                        double new_trigger = actor.getTrggerForce(target, distance);

                        if(new_trigger > strongest_trigger.triggerForce)
                        {
                            strongest_trigger.triggerForce = new_trigger;
                            strongest_trigger.setTriggerTypeWithObject(actor, target);
                            target_object = &target;
                        }
                    }
                }

                switch (actor.getGenome().getCommandToTrigger(strongest_trigger))
                {
                case Command::RANDOM_DIRECTION:
                {
                    double new_angle = getValueFromDiapasone(0, 360);
                    new_angle *= 180/PI;
                    actor.setRotateAngle(new_angle);
                    actor.Move();
                }
                    break;

                case Command::GO_FORWARD:
                {
                    actor.Move();
                }
                    break;

                case Command::ESCAPE:
                {
                    double new_angle = getAngleBetweenObjects(actor, *target_object);
                    actor.setRotateAngle(new_angle);
                    actor.Move();
                }
                    break;

                case Command::ATTACK:
                {
                    if(getDistance(actor, *target_object) <= actor.getGenome().getAttackRadius())
                    {
                        target_object->setEnergy(target_object->getEnergy() - actor.getGenome().getAttackForce());
                    }
                }
                    break;
                }
            }

        }

        if(var.getObjectType() == ObjectType::ORGANISM)
        {
            Organism &organism = *dynamic_cast<Organism*>(&var);
            organism.wasteEnergy();

            if(!organism.canBeAlive())
            {
                var.setObjectType(ObjectType::MEAT);
                var.setColor(Qt::red);
            }
        }
    }
}

