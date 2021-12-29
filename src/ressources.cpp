#include "ressources.h"
#include <boost/range/iterator_range.hpp>


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ressource_t

ressource_t::ressource_t(path_t const& path, type const type_) : m_path(path), m_type(type_)
{
}

auto ressource_t::get(int idx /* = 0 */) -> std::shared_ptr<ofImage> const&
{
	if ( m_images.empty() )
		load();

	return m_images[idx];
}

auto ressource_t::frame_count() -> unsigned
{
	if ( m_images.empty() )
		load();

	return m_images.size();
}

void ressource_t::load()
{
	switch ( m_type )
	{
		case type::single:
		{
			auto img = std::make_shared<ofImage>();
			img->load(ofFilePath::getAbsolutePath(m_path));
			m_images.push_back(img);
		}
		break;

		case type::collection:
		{
			auto directory = boost::filesystem::path{".\\bin\\data\\"};
			directory += m_path;

			for ( auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(directory), {}) )
			{
				auto const& path = entry.path();

				auto new_path = boost::filesystem::path{ "entities\\" + m_path.filename().string() + "\\"};
				new_path += path.filename();

				auto img = std::make_shared<ofImage>();
				img->load(ofFilePath::getAbsolutePath(new_path));
				m_images.push_back(img);
			}
		}
		break;
	}
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ressources_t

ressources_t::ressources_t()
{
	// Gathering the paths of all the backgrounds and entities

	auto backgrounds_location = boost::filesystem::path{ ".\\bin\\data\\backgrounds" };
	for ( auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(backgrounds_location), {}) )
	{
		auto const& path = entry.path();

		auto new_path = boost::filesystem::path{ "backgrounds\\" };
		new_path += path.filename();

		auto name = path.filename().replace_extension("").string();

		m_backgrounds[name] = std::make_unique<ressource_t>(new_path, ressource_t::type::single);
	}

	auto entities_location = boost::filesystem::path{ ".\\bin\\data\\entities" };
	for ( auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(entities_location), {}) )
	{
		auto const& path = entry.path();

		auto new_path = boost::filesystem::path{ "entities\\" };
		new_path += path.filename();

		auto name = path.filename().replace_extension("").string();

		if ( boost::filesystem::is_directory(path) )
			m_entities[name] = std::make_unique<ressource_t>(new_path, ressource_t::type::collection);
		else
			m_entities[name] = std::make_unique<ressource_t>(new_path, ressource_t::type::single);
	}
}

auto ressources_t::background(std::string const& name, int const idx /* = 0 */) -> std::shared_ptr<ofImage> const&
{
	return fetch_image(m_backgrounds, name, idx);
}

auto ressources_t::entity(std::string const& name, int const idx /* = 0 */) -> std::shared_ptr<ofImage> const&
{
	return fetch_image(m_entities, name, idx);
}

auto ressources_t::background_count() const -> unsigned const
{
	return m_backgrounds.size();
}

auto ressources_t::entity_count() const -> unsigned const
{
	return m_entities.size();
}

auto ressources_t::background_names() const -> std::vector<std::string>
{
	auto res = std::vector<std::string>{};

	for ( auto const& iter : m_backgrounds )
		res.push_back(iter.first);

	return res;
}

auto ressources_t::entity_names() const -> std::vector<std::string>
{
	auto res = std::vector<std::string>{};

	for ( auto const& iter : m_entities )
		res.push_back(iter.first);

	return res;
}

auto ressources_t::background_frame_count(std::string const& name) const -> unsigned
{
	return m_backgrounds.find(name)->second->frame_count();
}

auto ressources_t::entity_frame_count(std::string const& name) const -> unsigned
{
	return m_entities.find(name)->second->frame_count();
}

auto ressources() -> ressources_t&
{
	static auto _ = ressources_t{};
	return _;
}
