#include "entities.h"
#include <boost/range/iterator_range.hpp>
#include "ressources.h"
#include "simple_entity.h"
#include "animated_entity.h"

entities_t::entities_t()
{
}

auto entities_t::random_entity() const -> ent_t
{
	static auto names = ressources().entity_names();
	auto idx = unsigned{ rand() % names.size() };
	auto name = names[idx];

	if ( ressources().entity_frame_count(name) == 1u )
		return std::make_shared<simple_entity_t>(names[idx]);
	else
		return std::make_shared<animated_entity_t>(names[idx]);
}

auto entities() -> entities_t&
{
	static auto _ = entities_t{};
	return _;
}
