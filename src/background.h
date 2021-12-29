#pragma once

#include "ofMain.h"
#include <boost/filesystem.hpp>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// background_t class : Wrapper for a reference to a background image

class background_t
{
public:
	background_t(std::string const& name);

public:
	void update();
	void render() const;

private:
	std::string m_name;
	glm::vec2   m_pos;
};
