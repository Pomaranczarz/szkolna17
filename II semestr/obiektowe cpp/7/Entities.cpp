#include "Entities.hpp"

static const SimulationSettings& settings = SimulationSettings::getInstance();

Alga::Alga()
    : Organism(SimulationSettings::getInstance().algaMinHealth,
        SimulationSettings::getInstance().algaMaxHealth,
        SimulationSettings::getInstance().algaChildCost,
        SimulationSettings::getInstance().algaMealLimit)
    , Entity(SimulationSettings::getInstance().algaSign)
{

}

Fungus::Fungus()
    : Organism(SimulationSettings::getInstance().fungusMinHealth,
        SimulationSettings::getInstance().fungusMaxHealth,
        SimulationSettings::getInstance().fungusChildCost,
        SimulationSettings::getInstance().fungusMealLimit)
    , Entity(SimulationSettings::getInstance().fungusSign)
{

}

Bacteria::Bacteria()
    : Organism(SimulationSettings::getInstance().bacteriaMinHealth,
        SimulationSettings::getInstance().bacteriaMaxHealth,
        SimulationSettings::getInstance().bacteriaChildCost,
        SimulationSettings::getInstance().bacteriaMealLimit)
    , Entity(SimulationSettings::getInstance().bacteriaSign)
{

}

EntityType Alga::getType()
{
    return Organism::isAlive() ? EntityType::Alga : EntityType::Dead;
}

EntityType Fungus::getType()
{
    return Organism::isAlive() ? EntityType::Fungus : EntityType::Dead;
}

EntityType Bacteria::getType()
{
    return Organism::isAlive() ? EntityType::Bacteria : EntityType::Dead;
}

Entity* Alga::getChild()
{
    if (Organism::canReproduce())
        return new Alga();

    return nullptr;
}

Entity* Fungus::getChild()
{
    if (Organism::canReproduce())
        return new Fungus();

    return nullptr;
}

Entity* Bacteria::getChild()
{
    if (Organism::canReproduce())
        return new Bacteria();

    return nullptr;
}

void Alga::getTrophy(Entity* inhibitant)
{
    if (inhibitant)
        delete inhibitant;
}

void Fungus::getTrophy(Entity* inhibitant)
{
    if (inhibitant)
        if (inhibitant->getType() == EntityType::Corpse)
            delete inhibitant;
}

void Bacteria::getTrophy(Entity* inhibitant)
{
    if (inhibitant) {
        auto entityType = inhibitant->getType();
        if (entityType == EntityType::Alga || entityType == EntityType::Fungus)
            delete inhibitant;
    }

}

EntityAction Alga::chooseAction(Neighborhood neighborhood)
{
    Organism::simulationStep();

    if (Organism::isAlive() && Organism::canReproduce() && neighborhood.getNumberOfNeighborsOfType(EntityType::Void) > 0)
        return EntityIntent(EntityAction::Reproduce, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Void));

    if (Organism::isAlive() && Organism::canEat())
        Organism::eat();

    if (!Organism::isAlive() && symbol != settings.corpseSign)
        symbol = settings.corpseSign;

    return EntityIntent();
}

EntityAction Fungus::chooseAction(Neighborhood neighborhood)
{
    Organism::simulationStep();

    if (Organism::isAlive() && Organism::canReproduce() && neighborhood.getNumberOfNeighborsOfType(EntityType::Void) > 0)
        return EntityIntent(EntityAction::Reproduce, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Void));

    if (Organism::isAlive() && Organism::canEat() && neighborhood.getNumberOfNeighborsOfType(EntityType::Corpse) > 0)
        return EntityIntent(EntityAction::Decompose, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Corpse));

    if (!Organism::isAlive() && symbol != settings.corpseSign)
        symbol = settings.corpseSign;

    return EntityIntent();
}

EntityAction Bacteria::chooseAction(Neighborhood neighborhood)
{
    Organism::simulationStep();

    if (Organism::isAlive() && Organism::canReproduce() && neighborhood.getNumberOfNeighborsOfType(EntityType::Void) > 0)
        return EntityIntent(EntityAction::Reproduce, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Void));

    if (Organism::isAlive() && Organism::canEat() && neighborhood.getNumberOfNeighborsOfType(EntityType::Alga) > 0)
        return EntityIntent(EntityAction::Hunt, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Alga));

    if (Organism::isAlive() && Organism::canEat() && neighborhood.getNumberOfNeighborsOfType(EntityType::Bacteria) > 0)
        return EntityIntent(EntityAction::Hunt, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Bacteria));

    if (!Organism::isAlive() && symbol != settings.corpseSign)
        symbol = settings.corpseSign;

    return EntityIntent();
}