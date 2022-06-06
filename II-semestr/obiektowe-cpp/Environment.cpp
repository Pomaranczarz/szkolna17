#include "Environment.hpp"

Environment::Environment(unsigned rows, unsigned cols)
    : rows{rows}, columns{cols}, nicheCount{rows * cols}
{
    niche = new Niche *[rows];
    for (unsigned i = 0; i < rows; ++i)
        niche[i] = new Niche[cols];
}

Environment::~Environment()
{
    for (unsigned i = 0; i < rows; ++i)
        delete[] niche[i];

    delete[] niche;
}

void Environment::allocate(Entity *entity, unsigned row, unsigned col)
{
    if (row < rows && col < columns)
        niche[row][col].assignEntity(entity);
}

Neighborhood Environment::getNeighborhood(unsigned row, unsigned col) const
{
    Neighborhood neighborhood{EntityType::Wall};
    long row1, col1;

    for (Position position : {Position::P, Position::PG, Position::G, Position::LG, Position::L, Position::LD, Position::D, Position::PD})
    {
        row1 = row;
        col1 = col;

        Neighborhood::changeIndexesFromPosition(position, row1, col1);

        if (row1 >= 0 && row1 < rows && col1 >= 0 && col1 < columns)
            neighborhood.setNeighbor(position, niche[row1][col1].getEntityType());
    }

    return neighborhood;
}

unsigned long Environment::count(EntityType type) const
{
    unsigned long count{0};

    for (unsigned i = 0; i < rows; ++i)
        for (unsigned j = 0; j < columns; ++j)
            if (niche[i][j].getEntityType() == type)
                ++count;

    return count;
}

bool Environment::dead()
{
    return count(EntityType::Alga) + count(EntityType::Fungus) + count(EntityType::Bacteria) == 0;
}

void Environment::performJump(unsigned row, unsigned col)
{
    if (!niche[row][col].isEntityAlive() || niche[row][col].getEntityType() == EntityType::Alga)
        return;

    Neighborhood neighborhood = getNeighborhood(row, col);

    if (neighborhood.getNumberOfNeighborsOfType(EntityType::Void) > 0)
    {
        Position position = neighborhood.getPositionOfRandomNeighborOfType(EntityType::Void);

        unsigned int row1 = row, col1 = col;

        Neighborhood::changeIndexesFromPosition(position, row1, col1);

        niche[row1][col1] = niche[row][col];
    }
}

void Environment::performAction(unsigned row, unsigned col)
{
    if (!niche[row][col].isEntityAlive())
        return;

    Neighborhood neighborhood = getNeighborhood(row, col);

    EntityIntent intent = niche[row][col].activateEntity(neighborhood);

    unsigned row1 = row, col1 = col;
    Neighborhood::changeIndexesFromPosition(intent.where, row1, col1);

    Entity *entity = nullptr;

    switch (intent.action)
    {
    case EntityAction::None:
        performJump(row, col);
        break;
    case EntityAction::Reproduce:
        entity = niche[row][col].releaseChild();
        niche[row1][col1].assignEntity(entity);
        break;
    case EntityAction::Hunt:
    case EntityAction::Decompose:
        entity = niche[row1][col1].getEntity();
        niche[row][col].getTrophy(entity);
        break;
    }
}

void Environment::simulationStep()
{
    Index2DVec randomIndexes = GEN::getRandomIndexes(rows, columns);

    for (auto index : randomIndexes)
        performAction(index.row, index.column);
}

std::string Environment::toString() const
{
    std::string str{};

    char sep = SimulationSettings::getInstance().separatorSign;

    for (unsigned i = 0; i < rows; ++i)
    {
        for (unsigned j = 0; j < columns; ++j)
        {
            str += niche[i][j].getSymbol();
            str += sep;
        }

        str += "\n";
    }

    str += "\n Glony * : " + std::to_string(count(EntityType::Alga)) + "\n Grzyby # : " + std::to_string(count(EntityType::Fungus)) + "\n Bakterie @ : " + std::to_string(count(EntityType::Bacteria)) + "\n Martwe + : " + std::to_string(count(EntityType::Corpse)) + '\n';

    return str;
}

std::ostream &operator<<(std::ostream &out, const Environment &env)
{
    return out << env.toString();
}

Environment Environment::readFromFile(const std::string &filename)
{
    std::ifstream in{filename};

    std::stringstream text{};

    if (in)
    {
        text << in.rdbuf();
        in.close();
    }

    std::string saved = text.str();

    unsigned rows = 0, cols = 0;
    bool firstLine = true;

    for (char c : saved)
    {
        if (c != '\n')
        {
            if (firstLine && c != ' ')
                cols++;
        }
        else
        {
            firstLine = false;
            if (c == '\n')
                rows++;
        }
    }

    Environment env{rows, cols};

    char alga = SimulationSettings::getInstance().algaSign;
    char fungus = SimulationSettings::getInstance().fungusSign;
    char bacteria = SimulationSettings::getInstance().bacteriaSign;
    char empty = SimulationSettings::getInstance().voidSign;
    char c;

    for (unsigned int w = 0; w < rows; ++w)
    {
        std::getline(text, saved);
        for (unsigned int k = 0; k < 2 * cols; k += 2)
        {
            c = k < saved.size() ? saved[k] : empty;
            if (c == alga)
                env.allocate(new Alga(), w, k / 2);
            else if (c == fungus)
                env.allocate(new Fungus(), w, k / 2);
            else if (c == bacteria)
                env.allocate(new Bacteria(), w, k / 2);
        }
    }

    return env;
}