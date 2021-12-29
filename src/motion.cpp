#include "motion.h"

#include "ofMain.h"

motion_t::motion_t()
{
    m_type = static_cast<motion_type>(rand() % static_cast<int>(motion_type::_count));

    m_timeline.randomize();

    m_timeline.lower_boundary(0);
    m_timeline.higher_boundary(999999);
}

auto motion_t::get() const -> transforms_t
{
    auto t = m_timeline.cursor() * m_ex;

    switch ( m_type )
    {
    case motion_t::motion_type::mirror:     return get_mirror(t);     break;
    case motion_t::motion_type::four:       return get_four(t);       break;
    case motion_t::motion_type::bloom:      return get_bloom(t);      break;
    case motion_t::motion_type::go_through: return get_go_through(t); break;
    default: return {};                                               break;
    }
}

void motion_t::update()
{
    m_timeline.update();
}

auto motion_t::get_mirror(float t) const -> transforms_t
{
    auto res = transforms_t{};

    res.push_back({});
    res.push_back({});

    float split_amp = ofGetWidth() * (0.4 + cosf(t) * 0.05);
    float y_offset = 0.0f;

    res[0].m_pos.x = ofGetWidth() * 0.5f - split_amp;
    res[0].m_pos.y = ofGetWidth() * 0.5f + y_offset;
    res[1].m_pos.x = ofGetWidth() * 0.5f + split_amp;
    res[1].m_pos.y = ofGetWidth() * 0.5f + y_offset;

    return res;
}

auto motion_t::get_four(float t) const -> transforms_t
{
    auto res = transforms_t{};

    res.push_back({});
    res.push_back({});
    res.push_back({});
    res.push_back({});

    auto amp = ofGetWidth() * 0.3f;
    auto center = glm::vec2{ofGetWidth() * 0.5f, ofGetHeight() * 0.5f };

    res[0].m_pos.x = center.x - amp;
    res[0].m_pos.y = center.y - amp;
    res[1].m_pos.x = center.x - amp;
    res[1].m_pos.y = center.y + amp;
    res[2].m_pos.x = center.x + amp;
    res[2].m_pos.y = center.y - amp;
    res[3].m_pos.x = center.x + amp;
    res[3].m_pos.y = center.y + amp;

    return res;
}

auto motion_t::get_bloom(float t) const -> transforms_t
{
    auto res = transforms_t{};

    res.push_back({});

    auto center = glm::vec2{ ofGetWidth() * 0.5f, ofGetHeight() * 0.5f };
    res[0].m_pos.x = center.x;
    res[0].m_pos.y = center.y;
    res[0].m_scale = 1.0f + sinf(t) * 0.1f;

    return res;
}

auto motion_t::get_go_through(float t) const -> transforms_t
{
    auto res = transforms_t{};

    res.push_back({});
    res.push_back({});

    float split_amp = ofGetWidth() * (0.4 + cosf(t) * 0.05);
    float p = fmod(t, static_cast<float>(ofGetWidth()));

    res[0].m_pos.x = p;
    res[0].m_pos.y = ofGetWidth() * 0.5f + split_amp;
    res[1].m_pos.x = ofGetWidth() - p;
    res[1].m_pos.y = ofGetWidth() * 0.5f - split_amp;

    return res;
}
