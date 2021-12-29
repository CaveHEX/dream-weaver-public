#include "scene.h"
#include <thread>


scene_t::scene_t()
{
	auto entity_count = rand() % 6u + 1u;

	for ( auto i = unsigned{}; i < entity_count; ++i )
		m_entities.push_back(entities().random_entity());

	m_background = backgrounds().random_background();
}

void scene_t::update()
{
	m_background->update();

	for ( auto& ent : m_entities )
		ent->update();
}

void scene_t::render() const
{
	m_background->render();

	for ( auto& ent : m_entities )
		ent->render();
}
