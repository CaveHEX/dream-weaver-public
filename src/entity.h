#pragma once

#include <string>
#include <glm/glm.hpp>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// entity_t class : Base (abstract) class - Holds common information about entities displayed on the screen

class entity_t
{
	using name_t = std::string;

public:
	entity_t(std::string name);

public:
	virtual void update() = 0;
	virtual void render() const = 0;

	auto pos() const -> glm::vec2 const&;
	void pos(glm::vec2 const& pos);
	auto name() const -> std::string const&;

protected:
	glm::vec2   m_pos;
	std::string m_name;
};
