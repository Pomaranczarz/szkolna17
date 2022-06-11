#include "Niche.hpp"

Niche::Niche()
    : entity{ nullptr } {
}

Niche::Niche(Niche& another) {
	if (another.occupied()) {
		entity = another.entity;
		another.entity = nullptr;
	}
	else {
		entity = nullptr;
	}
}

Niche::~Niche() {
	if (entity != nullptr)
		delete entity;
}

Niche& Niche::operator=(Niche& another) {
	std::swap(entity, another.entity);
	return *this;
}

void Niche::assignEntity(Entity* homelessEntity) {
	if (!occupied()) {
		entity = homelessEntity;
		homelessEntity = nullptr;
	}
}

Entity* Niche::getEntity() {
	Entity* tmp = entity;
	if (occupied()) {
		tmp = entity;
		entity = nullptr;
	}

	return tmp;
}

bool Niche::isEntityAlive() const {
	if (occupied()) {
		EntityType type = entity->getType();
		return type == EntityType::Alga || type == EntityType::Fungus || type == EntityType::Bacteria;
	}
	else
		return false;
}

char Niche::getSymbol() const {
	if (!occupied())
		return SimulationSettings::getInstance().voidSign;
	else
		return entity->getSymbol();
}