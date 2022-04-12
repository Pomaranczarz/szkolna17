#pragma once

#include "../3/Organism.hpp"
#include "../6/Entity.hpp"

class Alga : public Organism, public Entity
{
public:
    Alga();
    virtual EntityType getType() final;
    virtual EntityIntent chooseAction(Neighborhood neighborhood);
    virtual Entity* getChild();
    virtual void getTrophy(Entity* inhibitant);
};

class Fungus : public Organism, public Entity
{
public:
    Fungus();
    virtual EntityType getType() final;
    virtual EntityIntent chooseAction(Neighborhood neighborhood);
    virtual Entity* getChild();
    virtual void getTrophy(Entity* inhibitant);
};

class Bacteria : public Organism, public Entity
{
public:
    Bacteria();
    virtual EntityType getType() final;
    virtual EntityIntent chooseAction(Neighborhood neighborhood);
    virtual Entity* getChild();
    virtual void getTrophy(Entity* inhibitant);
};