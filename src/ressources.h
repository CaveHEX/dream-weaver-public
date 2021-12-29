#pragma once

#include "ofMain.h"
#include <vector>
#include <unordered_map>
#include <boost/filesystem.hpp>


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ressource_t class : Holds a sprite - or a collection of images (Normalized at 24 FPS) - Only loads it on first use

class ressource_t
{
	using path_t = boost::filesystem::path;

public:
	enum class type { single, collection };

public:
	ressource_t(path_t const& path, type const type_);

public:
	auto get(int idx = 0) -> std::shared_ptr<ofImage> const&;
	auto frame_count() -> unsigned;

private:
	void load();

private:
	type const m_type;
	path_t m_path;
	std::vector<std::shared_ptr<ofImage>> m_images;
};


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ressources_t class : Loads, holds and shares all the raster buffers

class ressources_t
{
	using map_t = std::unordered_map<std::string, std::unique_ptr<ressource_t>>;

public:
	ressources_t();

public:
	auto background(std::string const& name, int const idx = 0) -> std::shared_ptr<ofImage> const&;
	auto entity(std::string const& name, int const idx = 0) -> std::shared_ptr<ofImage> const&;
	auto background_count() const -> unsigned const;
	auto entity_count() const -> unsigned const;
	auto background_names() const->std::vector<std::string>;
	auto entity_names() const -> std::vector<std::string>;
	auto background_frame_count(std::string const& name) const -> unsigned;
	auto entity_frame_count(std::string const& name) const -> unsigned;

private:
	template <typename Map> inline
	auto fetch_image(Map const& map, std::string const& name, int idx) -> std::shared_ptr<ofImage> const&;

private:
	map_t m_backgrounds;
	map_t m_entities;
};


auto ressources() -> ressources_t&;

template <typename Map> inline
auto ressources_t::fetch_image(Map const& map, std::string const& name, int idx) -> std::shared_ptr<ofImage> const&
{
	auto iter = map.find(name);

	if ( iter == map.end() )
		throw unexpected; // [VDH] Proper handling

	return iter->second->get(idx);
}
