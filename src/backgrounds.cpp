#include "backgrounds.h"
#include <boost/range/iterator_range.hpp>
#include <boost/filesystem.hpp>
#include "ressources.h"

backgrounds_t::backgrounds_t()
{
}

auto backgrounds_t::random_background() const -> std::shared_ptr<background_t>
{
	static auto names = ressources().background_names();
	auto idx = unsigned{rand() % names.size()};

	return std::make_shared<background_t>(names[idx]);
}

auto backgrounds() -> backgrounds_t&
{
	static auto _ = backgrounds_t{};
	return _;
}
