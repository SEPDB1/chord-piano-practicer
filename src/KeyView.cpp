#include "KeyView.h"
#include "Renderer.h"

KeyView::KeyView(KeyModel& model, const SDL_FRect& bounds, bool isWhite, std::array<std::unique_ptr<SDL_FRect>, 2> hitboxes)
	: m_Model{ model }
	, m_BorderBounds{ bounds }
	, m_InsideBounds{ Utils::ScaleByPixels(bounds, -m_BorderSize) }
	, m_SelectedBounds{ Utils::ScaleByPixels(bounds, m_SelectedBorderSize) }
	, m_Hitboxes{ std::move(hitboxes) }
	, m_IsWhite{ isWhite }
{
	model.SetObserver(this);
}

KeyView::~KeyView() noexcept
{
	m_Model.RemoveObserver();
}

void KeyView::Render() const
{
	const Renderer& r{ Renderer::GetInstance() };

	if (m_Model.IsPressed())
	{
		r.SetDrawColor(Note::MidiToColor(m_Model.GetMidi()));
		r.FillRect(std::addressof(m_BorderBounds));
	}
	else
	{
		r.SetDrawColor(m_Black);
		r.FillRect(std::addressof(m_BorderBounds));

		Utils::Color4ub drawColor;
		if (m_Model.IsSelected())
			drawColor = m_Highlight;
		else
			drawColor = (m_IsWhite) ? m_White : m_Black;

		r.SetDrawColor(drawColor);
		r.FillRect(std::addressof(m_InsideBounds));
	}

}

void KeyView::OnNotify(uint8_t eventId)
{

}

bool KeyView::IsWhite() const
{
	return m_IsWhite;
}

bool KeyView::IsOverlapping(const SDL_FPoint& point) const
{
	for (const auto& pHitbox : m_Hitboxes)
	{
		if (SDL_PointInRectFloat(std::addressof(point), pHitbox.get()))
			return true;
	}
	return false;
}

KeyModel& KeyView::GetModel() const
{
	return m_Model;
}
