#pragma once

#include "entity.h"


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// simple_entity_t class : An entity with no animation

class simple_entity_t : public entity_t
{
public:
	simple_entity_t(std::string const& name);

public:
	void update() override;
	void render() const override;
};
