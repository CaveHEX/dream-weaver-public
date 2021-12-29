#include "simple_entity.h"
#include "ressources.h"
#include <boost/range/iterator_range.hpp>
#include "tools.h"


simple_entity_t::simple_entity_t(std::string const& name) : entity_t(name)
{
	auto img = ressources().entity(m_name);
	tools::center_image(m_pos, img);
}

void simple_entity_t::update()
{
}

void simple_entity_t::render() const
{
	ressources().entity(m_name)->draw(m_pos);
}
