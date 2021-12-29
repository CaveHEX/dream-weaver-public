#include "background.h"
#include "ressources.h"
#include "tools.h"


background_t::background_t(std::string const& name) : m_name(name)
{
	auto img = ressources().background(m_name);
	tools::center_image(m_pos, img);
}

void background_t::update()
{
}

void background_t::render() const
{
	ressources().background(m_name)->draw(m_pos);
}
