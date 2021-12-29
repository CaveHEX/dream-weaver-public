#include "animated_entity.h"
#include <boost/range/iterator_range.hpp>
#include "ressources.h"
#include "tools.h"

animated_entity_t::animated_entity_t(std::string const& name) : entity_t(name)
{
	auto img = ressources().entity(m_name);
	tools::center_image(m_pos, img);

	m_timeline.randomize();

	m_timeline.lower_boundary(0);
	m_timeline.higher_boundary(ressources().entity_frame_count(m_name) - 1);
}

void animated_entity_t::update()
{
	m_timeline.update();
	m_motion.update();
}

void animated_entity_t::render() const
{
	auto const& img = ressources().entity(m_name, m_timeline.cursor());

	for ( auto const& motion : m_motion.get() ) // [VDH] Make this a method in motion_t - takes the img as the argument
	{
		ofPushMatrix();
		ofTranslate(motion.m_pos);
		ofScale(motion.m_scale);
		ofRotateRad(motion.m_angle);
		img->draw(img->getWidth() * -0.5, img->getHeight() * -0.5);
		ofPopMatrix();
	}
}
