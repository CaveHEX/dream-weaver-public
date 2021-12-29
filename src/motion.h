#pragma once

#include "timeline.h"
#include <vector>
#include <glm/glm.hpp>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// transform_t class : Simple class to describe a transformation

class transform_t
{
public:
	transform_t() = default;

public:
	glm::vec2 m_pos{0.0f, 0.0f};
	float m_angle{0.0f};
	float m_scale{1.0f};
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// motion_t class : Describes the location(s) and transformations of an entity - evolves with time

class motion_t
{
	using transforms_t = std::vector<transform_t>;

public:
	enum class motion_type { mirror, four, bloom, go_through, _count };

public:
	motion_t();

public:
	auto get() const -> transforms_t;
	void update();

private:
	auto get_mirror(float t) const -> transforms_t;
	auto get_four(float t) const -> transforms_t;
	auto get_bloom(float t) const -> transforms_t;
	auto get_go_through(float t) const -> transforms_t;

private:
	motion_type m_type;
	timeline_t  m_timeline;
	float       m_ex{0.1f};
};
