#include "timeline.h"
#include "tools.h"
#include <math.h>


timeline_t::timeline_t(int lower_bound, int higher_bound) : m_lower_bound(lower_bound), m_higher_bound(higher_bound)
{
}

auto timeline_t::cursor() const -> int const&
{
	return time();
}

void timeline_t::cursor(int value)
{
	m_cursor = value;
}

void timeline_t::lower_boundary(int value)
{
	m_lower_bound = value;
}

void timeline_t::higher_boundary(int value)
{
	m_higher_bound = value;
}

void timeline_t::speed(int value)
{
	m_speed = value;
}

void timeline_t::add_effect(effect_type const effect)
{
	m_effects[static_cast<int>(effect)] = true;
}

void timeline_t::set_loop_behavior(boundary_behavior_type const behavior)
{
	m_boundary_behavior = behavior;
}

void timeline_t::randomize()
{
	if ( rand() % 100 > 70 )
		m_speed = -1;
	else
		m_speed = 1;

	if ( rand() % 100 > 70 )
		m_speed *= 2;

	if ( rand() % 100 < 50 )
		m_boundary_behavior = boundary_behavior_type::loop;
	else
		m_boundary_behavior = boundary_behavior_type::bounce;

	if ( rand() % 100 > 80 )
	{
		add_effect(effect_type::loopbacks);
		m_loopback_amp = 1 + rand() % 7;
		m_loopback_rate = rand() % 80 + 10;
	}

	if ( rand() % 100 > 80 )
	{
		add_effect(effect_type::skips);
		m_skips_amp = 1 + rand() % 7;
		m_skips_rate = rand() % 80 + 10;
	}
}

void timeline_t::update()
{
	m_cursor += m_speed;

	check_boundary();

	apply_effects();
}

void timeline_t::check_boundary()
{
	if ( m_cursor >= m_higher_bound )
		switch ( m_boundary_behavior )
		{
		case timeline_t::boundary_behavior_type::loop:
			m_cursor = m_lower_bound + (m_cursor - m_higher_bound);
			break;

		case timeline_t::boundary_behavior_type::bounce:
			m_speed *= -1;
			m_cursor = m_higher_bound;
			break;

		default:
			break;
		}

	if ( m_cursor < m_lower_bound )
	{
		switch ( m_boundary_behavior )
		{
		case timeline_t::boundary_behavior_type::loop:
			m_cursor = m_higher_bound - (m_lower_bound - m_cursor);
			break;

		case timeline_t::boundary_behavior_type::bounce:
			m_speed *= -1;
			m_cursor = m_lower_bound;
			break;

		default:
			break;
		}
	}
}

void timeline_t::apply_effects()
{
	if ( m_effects.test(static_cast<int>(effect_type::loopbacks)) )
		apply_loopbacks();

	if ( m_effects.test(static_cast<int>(effect_type::skips)) )
		apply_skips();
}

void timeline_t::apply_loopbacks()
{
	if ( rand() % 100 < m_loopback_rate )
	{
		auto step_ = m_loopback_amp * tools::sign(m_speed);

		if ( step_ == 0 )
			return;

		if ( step_ < 0 )
			if ( m_cursor + m_loopback_amp >= m_higher_bound )
				return;

		if ( step_ > 0 )
			if ( m_cursor - m_loopback_amp < m_lower_bound )
				return;

		m_cursor -= step_;

		check_boundary();
	}
}

void timeline_t::apply_skips()
{
	if ( rand() % 100 < m_skips_rate )
	{
		auto step_ = m_skips_amp * tools::sign(m_speed);

		if ( step_ == 0 )
			return;

		if ( step_ < 0 )
			if ( m_cursor + m_skips_amp >= m_higher_bound )
				return;

		if ( step_ > 0 )
			if ( m_cursor - m_skips_amp < m_lower_bound )
				return;

		m_cursor += step_;

		check_boundary();
	}
}

auto timeline_t::time() const -> int
{
	return m_cursor;
}
