#pragma once

#include "ofApp.h"

namespace tools
{
	template <typename T> inline int sign(T val) { return (T(0) < val) - (val < T(0)); }

	inline void center_image(glm::vec2& pos, std::shared_ptr<ofImage> const& img)
	{
		pos.x = ofGetWidth() * 0.5 - img->getWidth() * 0.5f;
		pos.y = ofGetHeight() * 0.5 - img->getHeight() * 0.5f;
	}
}
