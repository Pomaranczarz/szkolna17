#pragma once

enum class EntityType
{
	Alga,
	Fungus,
	Bacteria,
	Void,
	Wall,
	Corpse,
	Unknown,
};

enum class EntityAction
{
	Reproduce,
	Hunt,
	Decompose,
	None,
};

enum class Position
{
	P,
	PG,
	G,
	LG,
	L,
	LD,
	D,
	PD,
	Nowhere,
};

class SimulationSettings
{
public:
	const char
	    algaSign
	    = '*',
	    fungusSign = '#',
	    bacteriaSign = '@',
	    corpseSign = '+',
	    voidSign = '_',
	    separatorSign = ' ',
	    unknownSign = '?';

	unsigned short
	    algaMinHealth
	    = 5,
	    algaMaxHealth = 10,
	    algaChildCost = 2,
	    algaMealLimit = 6,

	    fungusMinHealth = 40,
	    fungusMaxHealth = 60,
	    fungusChildCost = 3,
	    fungusMealLimit = 30,

	    bacteriaMinHealth = 25,
	    bacteriaMaxHealth = 40,
	    bacteriaChildCost = 3,
	    bacteriaMealLimit = 10;

	[[nodiscard]] bool isValidSign(char sign) const {
		return sign == algaSign || sign == fungusSign || sign == bacteriaSign || sign == corpseSign || sign == voidSign || sign == unknownSign;
	}

	[[nodiscard]] bool isValidSeparator(char sign) const {
		return sign == separatorSign;
	}

private:
	SimulationSettings() = default;

public:
	static SimulationSettings& getInstance() {
		static SimulationSettings instance;
		return instance;
	}

	SimulationSettings(const SimulationSettings&) = delete;
	SimulationSettings(SimulationSettings&&) = delete;
	SimulationSettings& operator=(const SimulationSettings&) = delete;
	SimulationSettings& operator=(SimulationSettings&&) = delete;
};