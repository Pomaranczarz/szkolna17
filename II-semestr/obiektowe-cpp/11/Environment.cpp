#include "Environment.hpp"

Environment::Environment(unsigned rows, unsigned cols)
    : rows{ rows }
    , cols{ cols }
    , nicheCount{ rows * cols }
{
    niche = new Niche * [rows];
    for (unsigned i = 0; i < rows; ++i)
        niche[i] = new Niche[cols];
}

Environment::~Environment() {
    for (unsigned i = 0; i < rows; ++i)
        delete [] niche[i];

    delete [] niche;
}

void Environment::allocate(Entity* entity, unsigned row, unsigned col) {
    if (row < rows && col < columns)
        niche[row][col].assignEntity(entity);
}

Neighborhood Environment::getNeighborhood(unsigned row, unsigned col) const {
    Neighborhood neighborhood{ EntityType::Wall };
    long row1, col1;

    for (Position position : { Position::P, Position::PG, Position::G, Position::LG, Position::L, Position::LD, Position::D, Position::PD }) {
        row1 = row;
        col1 = col;

        Neighborhood::changeIndexesFromPosition(position, row1, col1);

        if (row1 >= 0 && row1 < rows && col1 >= 0 && col1 < columns)
            neighborhood.setNeighbor(position, niche[row1][col1].getEntityType());
    }

    return neighborhood;
}

unsigned long Environment::count(EntityType type) const {
    unsigned long count{ 0 };

    for (unsigned i = 0; i < rows; ++i)
        for (unsigned j = 0; j < cols; ++j)
            if (niche[i][j].getEntityType() == type)
                ++count;

    return count;
}

bool dead() {
    return count(EntityType::Alga) + count(EntityType::Fungus) + count(EntityType::Bacteria) == 0;
}

void Environment::performJump(unsigned row, unsigned col) {
    if (!niche[row][col].isEntityAlive() || niche[row][col].getEntityType() == EntityType::Alga)
        return;

    Neighborhood neighborhood = getNeighborhood(row, col);

    if (neighborhood.getNumberOfNeighborsOfType(EntityType::Void) > 0) {
        Position position = neighborhood.getPositionOfRandomNeighborOfType(EntityType::Void);

        unsigned int ro1 = row, col1 = col;

        Neighborhood::changeIndexesFromPosition(position, ro1, col1);

        niche[row1][col1] = niche[row][col];
    }
}

void Environment::performAction(unsigned row, unsigned col) {
    if (!niche[row][col].isEntityAlive())
        return;

    Neighborhood neighborhood = getNeighborhood(row, col);

    EntityIntent intent = niche[row][col].activateEntity(neighborhood);

    unsigned row1 = row, col1 = col;
    Neighborhood::changeIndexesFromPosition(intent.position, row1, col1);

    Entity* entity = nullptr;

    switch (intent.action) {
    case EntityAction::None:
        performJump(row, col); break;
    case EntityAction::ReleaseChild:
        entity = niche[row][col].releaseChild();
        niche[row1][col1].assignEntity(entity);
        break;
    case EntityAction::GetTrophy:
    case EntityAction::Decompose:
        entity = niche[row1][col1].getEntity();
        niche[row][col].getTrophy(entity);
        break;
    }
}

void Environment::simulationStep() {
    Index2DVec randomIndexes = RandomGenerator::getRandomIndexes(rows, columns);

    for (auto index : randomIndexes)
        performAction(index.row, index.col);
}

std::string Environment::toString() const {
    std::string str{};

    char sep = SimulationSettings::getInstance().separatorSign;

    for (unsigned i = 0; i < rows; ++i) {
        for (unsigned j = 0; j < cols; ++j)
            str += niche[i][j].getEntityType() + sep;

        str += "\n";
    }

    str += "\n Glony * : "
        + std::to_string(count(EntityType::Alga))
        + "\n Grzyby # : "
        + std::to_string(count(EntityType::Fungus))
        + "\n Bakterie @ : "
        + std::to_string(count(EntityType::Bacteria))
        + "\n Martwe + : "
        + std::to_string(count(EntityType::Dead)) + '\n';

    return str;
}