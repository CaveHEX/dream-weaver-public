#pragma once

#include "ofMain.h"
#include "entity.h"
#include "timeline.h"
#include "motion.h"
#include <vector>
#include <tuple>
#include <boost/filesystem.hpp>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// animated_entity_t class : Describes an sprite - the way it will be animated over time and its location(s) on the screen

class animated_entity_t : public entity_t
{
	using path_t = boost::filesystem::path;

public:
	animated_entity_t(std::string const& name);

public:
	void update() override;
	void render() const override;

private:
	timeline_t m_timeline; // Drives the frames animation
	motion_t   m_motion;   // Describes the location(s)
};
