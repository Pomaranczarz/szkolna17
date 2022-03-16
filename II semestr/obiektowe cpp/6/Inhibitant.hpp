#pragma once

#include "../4/Settings.hpp"
#include "InhibitantIntent.hpp"
#include "../5/Neighborhood.hpp"

class Inhibitant
{
public:
    Inhibitant(char symbol = SimulationSettings::getInstance().unknownSign);
    Inhibitant(const Inhibitant& inhibitant);

    [[nodiscard]] virtual char getSymbol() const final;
    virtual ~Inhibitant();
    [[nodiscard]] virtual InhibitantType whoAreYou() = 0;
    [[nodiscard]] virtual InhibitantIntent chooseAction(Neighborhood neighborhood) = 0;
    [[nodiscard]] virtual Inhibitant* getChild() = 0;
    virtual void getTrophy(Inhibitant* inhibitant) = 0;

protected:
    char symbol;
};