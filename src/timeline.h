#pragma once

#include <bitset>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// timeline_t class : A timer on which effects and constraints can be applied

class timeline_t
{
public:
	enum class boundary_behavior_type { loop, bounce };
	enum class effect_type            { loopbacks, skips, sin, _count };

	using effects_t = std::bitset<static_cast<int>(effect_type::_count)>;

public:
	timeline_t() = default;
	timeline_t(int lower_bound, int higher_bound);

public:
	auto cursor() const -> int const&;
	void cursor(int value);
	void lower_boundary(int value);
	void higher_boundary(int value);
	void speed(int value);
	void add_effect(effect_type const effect);
	void set_loop_behavior(boundary_behavior_type const behavior);
	void randomize();

	void update();

private:
	void check_boundary();

	void apply_effects();
	void apply_loopbacks();
	void apply_skips();

	auto time() const -> int;

private:
	// Location and playback speed
	int m_speed{1};
	int m_cursor{0};

	// Boundaries
	int m_lower_bound{0};
	int m_higher_bound{0};
	
	// Behaviors
	boundary_behavior_type m_boundary_behavior{boundary_behavior_type::loop};
	effects_t              m_effects;

	// Loopbacks
	int m_loopback_amp{5};
	int m_loopback_rate{10};

	int m_skips_amp{5};
	int m_skips_rate{10};

	float m_sin_amp{5.0f};
	float m_sin_freq{0.05f};
};
