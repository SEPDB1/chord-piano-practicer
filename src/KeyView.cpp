#include "KeyView.h"
#include "Renderer.h"

KeyView::KeyView(KeyModel& model, const SDL_FRect& bounds, bool isWhite, std::array<std::unique_ptr<SDL_FRect>, 2> hitboxes)
	: m_Model{ model }
	, m_BorderBounds{ bounds }
	, m_InsideBounds{ Utils::ScaleByPixels(bounds, -m_BorderSize) }
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

void KeyView::OnNotify(uint8_t eventId)
{

}

bool KeyView::IsWhite() const
{
	return m_IsWhite;
}

KeyModel& KeyView::GetModel() const
{
	return m_Model;
}

const std::array<std::unique_ptr<SDL_FRect>, 2>& KeyView::GetHitboxes() const
{
	return m_Hitboxes;
}
