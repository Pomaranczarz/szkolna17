#pragma once

#include "../3/Organism.hpp"
#include "../6/Entity.hpp"

class Alga : public Organsim, public Entity
{
public:
    Alga();
    virtual [[nodiscard]] EntityType getType() final;
    virtual [[nodiscard]] EntityIntent chooseAction(Neighborhood neighborhood);
    virtual [[nodiscard]] Entity* getChild();
    virtual void getTrophy(Entity* inhibitant);
};

class Fungus : public Organsim, public Entity
{
public:
    Fungus();
    virtual [[nodiscard]] EntityType getType() final;
    virtual [[nodiscard]] EntityIntent chooseAction(Neighborhood neighborhood);
    virtual [[nodiscard]] Entity* getChild();
    virtual void getTrophy(Entity* inhibitant);
};

class Bacteria : public Organsim, public Entity
{
public:
    Bacteria();
    virtual [[nodiscard]] EntityType getType() final;
    virtual [[nodiscard]] EntityIntent chooseAction(Neighborhood neighborhood);
    virtual [[nodiscard]] Entity* getChild();
    virtual void getTrophy(Entity* inhibitant);
};