#include "Inhibitant.hpp"

Inhibitant::Inhibitant(char symbol)
    : symbol{ symbol }
{

}

Inhibitant::Inhibitant(const Inhibitant& inhibitant)
    : symbol{ inhibitant.symbol }
{

}

char Inhibitant::getSymbol() const
{
    return symbol;
}

Inhibitant::~Inhibitant()
{

}