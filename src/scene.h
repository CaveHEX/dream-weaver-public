#pragma once

#include "entity.h"
#include "backgrounds.h"
#include "entities.h"
#include <vector>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// scene_t class : A scene is composed of a background and a collection of entites - it simply delegates the updates and rendering calls

class scene_t
{
public:
	scene_t();

public:
	void update();
	void render() const;

private:
	std::shared_ptr<background_t>          m_background;
	std::vector<std::shared_ptr<entity_t>> m_entities;
};
