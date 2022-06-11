#pragma once

#include "Settings.hpp"

class EntityIntent
{
public:
	const EntityAction action;
	const Position where;

	EntityIntent(EntityAction action = EntityAction::None, Position where = Position::Nowhere)
	    : action{ action }
	    , where{ where } {
	}
};