#include "entity.h"


entity_t::entity_t(std::string name) : m_name(name)
{
}

auto entity_t::pos() const -> glm::vec2 const&
{
	return m_pos;
}

void entity_t::pos(glm::vec2 const& pos)
{
	m_pos = pos;
}

auto entity_t::name() const -> std::string const&
{
	return m_name;
}
