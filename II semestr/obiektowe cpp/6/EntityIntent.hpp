#pragma once

#include "../4/Settings.hpp"

class EntityIntent
{
public:
    const EntityAction action;
    const Position where;

    EntityIntent(EntityAction action = NOTHING, Position where = NOWHERE)
        : action{ action }
        , where{ where }
    {

    }

};