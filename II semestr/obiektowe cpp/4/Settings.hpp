#pragma once

/// Enum representing type of entity in simulation.
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

/// Enum representing action that entity can take each simultion step.
enum class EntityAction
{
    Reproduce,
    Hunt,
    Decompose,
    None,
};


/// Enum representing position of entinty in simulation.
enum class Position
{
    P, PG, G, LG, L, LD, D, PD, Nowhere,
};

class SimulationSettings
{
public:
    /// Sign representing entity type.
    const char
        algaSign = '*',
        fungusSign = '#',
        bacteriaSign = '@',
        corpseSign = '+',
        voidSign = '_',
        separatorSign = ' ',
        unknownSign = '?';

    unsigned short
        algaMinHealth = 5,
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

    /// Check if given character is valid entity sign.
    [[nodiscard]] bool isValidSign(char sign) const {
        return
            sign == algaSign ||
            sign == fungusSign ||
            sign == bacteriaSign ||
            sign == corpseSign ||
            sign == voidSign ||
            sign == unknownSign;
    }

    /// Check if given character is valid separator.
    [[nodiscard]] bool isValidSeparator(char sign) const {
        return sign == separatorSign;
    }

private:
    SimulationSettings() = default;

public:
    /// Get reference to the instance of SimulationSettings.
    static SimulationSettings& getInstance() {
        static SimulationSettings instance;
        return instance;
    }

    // Made public for better error messages
    SimulationSettings(const SimulationSettings&) = delete;
    SimulationSettings(SimulationSettings&&) = delete;
    SimulationSettings& operator=(const SimulationSettings&) = delete;
    SimulationSettings& operator=(SimulationSettings&&) = delete;
};