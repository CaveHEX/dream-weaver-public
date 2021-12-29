#pragma once

#include "background.h"
#include <vector>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// backgrounds_t class : Tool to obtain a background image

class backgrounds_t
{
public:
	backgrounds_t();

public:
	auto random_background() const -> std::shared_ptr<background_t>;

private:
};

auto backgrounds() -> backgrounds_t&;
