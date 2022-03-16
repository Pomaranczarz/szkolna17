#pragma once

class InhibitantAction;
class Position;

class InhibitantIntent
{
public:
    const InhibitantAction action;
    const Position where;

    InhibitantIntent(InhibitantAction action = NOTHING, Position where = NOWHERE)
        : action{ action }
        , where{ where }
    {

    }

};