#pragma once

#include <vector>
#include "entity.h"
#include <memory>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// entities_t class : Tool to obtain an entity

class entities_t
{
	using ent_t = std::shared_ptr<entity_t>;

public:
	entities_t();

public:
	auto random_entity() const -> ent_t;
};

auto entities() -> entities_t&;
