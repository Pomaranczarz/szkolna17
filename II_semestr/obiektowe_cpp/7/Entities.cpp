#include "Entities.hpp"

static const SimulationSettings& settings = SimulationSettings::getInstance();

Alga::Alga()
    : Organism(
        GEN::randBetween(settings.algaMinHealth, settings.algaMaxHealth),
        settings.algaMealLimit,
        settings.algaChildCost)
    , Entity(SimulationSettings::getInstance().algaSign)
{

}

Fungus::Fungus()
    : Organism(
        GEN::randBetween(settings.fungusMinHealth, settings.fungusMaxHealth),
        settings.fungusMealLimit,
        settings.fungusChildCost)
    , Entity(SimulationSettings::getInstance().fungusSign)
{

}

Bacteria::Bacteria()
    : Organism(
        GEN::randBetween(settings.bacteriaMinHealth, settings.bacteriaMaxHealth),
        settings.bacteriaMealLimit,
        settings.bacteriaChildCost)
    , Entity(SimulationSettings::getInstance().bacteriaSign)
{

}

EntityType Alga::getType()
{
    return Organism::isAlive() ? EntityType::Alga : EntityType::Corpse;
}

EntityType Fungus::getType()
{
    return Organism::isAlive() ? EntityType::Fungus : EntityType::Corpse;
}

EntityType Bacteria::getType()
{
    return Organism::isAlive() ? EntityType::Bacteria : EntityType::Corpse;
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

EntityIntent Alga::chooseAction(Neighborhood neighborhood)
{
    simulationStep();

    if (isAlive() && canReproduce() && neighborhood.getNumberOfNeighborsOfType(EntityType::Void) > 0)
        return EntityIntent(EntityAction::Reproduce, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Void));

    if (isAlive() && isHungry())
        Organism::eat();

    if (!isAlive() && symbol != settings.corpseSign)
        symbol = settings.corpseSign;

    return EntityIntent();
}

EntityIntent Fungus::chooseAction(Neighborhood neighborhood)
{
    Organism::simulationStep();

    if (isAlive() && canReproduce() && neighborhood.getNumberOfNeighborsOfType(EntityType::Void) > 0)
        return EntityIntent(EntityAction::Reproduce, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Void));

    if (isAlive() && isHungry() && neighborhood.getNumberOfNeighborsOfType(EntityType::Corpse) > 0)
        return EntityIntent(EntityAction::Decompose, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Corpse));

    if (!isAlive() && symbol != settings.corpseSign)
        symbol = settings.corpseSign;

    return EntityIntent();
}

EntityIntent Bacteria::chooseAction(Neighborhood neighborhood)
{
    Organism::simulationStep();

    if (isAlive() && canReproduce() && neighborhood.getNumberOfNeighborsOfType(EntityType::Void) > 0)
        return EntityIntent(EntityAction::Reproduce, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Void));

    if (isAlive() && isHungry() && neighborhood.getNumberOfNeighborsOfType(EntityType::Alga) > 0)
        return EntityIntent(EntityAction::Hunt, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Alga));

    if (isAlive() && isHungry() && neighborhood.getNumberOfNeighborsOfType(EntityType::Bacteria) > 0)
        return EntityIntent(EntityAction::Hunt, neighborhood.getPositionOfRandomNeighborOfType(EntityType::Bacteria));

    if (!isAlive() && symbol != settings.corpseSign)
        symbol = settings.corpseSign;

    return EntityIntent();
}