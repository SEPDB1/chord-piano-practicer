#include "KeyboardView.h"
#include "Renderer.h"
#include <array>

KeyboardView::KeyboardView(KeyboardModel& model, const SDL_FPoint& center)
	: m_Model{ model }
	, m_Center{ center }
{
	model.SetObserver(this);
	CreateKeys();
}

KeyboardView::~KeyboardView() noexcept
{
	m_Model.RemoveObserver();
}

void KeyboardView::Render() const
{
	for (const KeyView& key : m_Keys)
	{
		if (key.IsWhite())
			key.Render();
	}

	for (const KeyView& key : m_Keys)
	{
		if (!key.IsWhite())
			key.Render();
	}
}

void KeyboardView::OnNotify(uint8_t eventId)
{

}

std::vector<KeyView>& KeyboardView::GetKeyViews()
{
	return m_Keys;
}

const std::vector<KeyView>& KeyboardView::GetKeyViews() const
{
	return m_Keys;
}

void KeyboardView::CreateKeys()
{
	auto& keyModels{ m_Model.GetKeys() };
	const size_t nrKeys{ keyModels.size() };

	m_Keys.reserve(nrKeys);

	SDL_FPoint center{ Renderer::GetWidth() / 2.f, Renderer::GetHeight() / 2.f };
	SDL_FPoint startPoint{ 
		center.x - (m_WidthBlackKey) * (nrKeys * 7.f / 12.f),
		center.y + 50.f
	};
	std::array<std::unique_ptr<SDL_FRect>, 2> hitboxes{};

	for (size_t i{ 0 }; i < nrKeys; ++i)
	{
		SDL_FRect bounds;
		bool isWhite = Note::IsWhite(keyModels[i].GetMidi());
		if (isWhite)
		{
			bounds = {
				startPoint.x,
				startPoint.y - m_HeightWhiteKey / 2.f,
				m_WidthWhiteKey,
				m_HeightWhiteKey
			};

			hitboxes[0] = std::make_unique<SDL_FRect>(
				bounds.x, 
				bounds.y + 
				m_HeightBlackKey, m_WidthWhiteKey, 
				m_HeightWhiteKey - m_HeightBlackKey
			);

			const size_t prevKey{ (i != 0) ? i - 1 : -1 };
			const size_t nextKey{ (i < nrKeys - 1) ? i + 1 : -1  };
			const bool prevIsBlack{ prevKey != -1 && !m_Keys[prevKey].IsWhite() };
			const bool nextIsBlack{ nextKey != -1 && !Note::IsWhite(keyModels[nextKey].GetMidi()) };
			SDL_FRect secondHitbox{ bounds.x, bounds.y, bounds.w, m_HeightBlackKey };

			if (prevIsBlack)
			{
				secondHitbox.x += m_WidthBlackKey / 2.f;
				secondHitbox.w -= m_WidthBlackKey / 2.f;
			}

			if (nextIsBlack)
				secondHitbox.w -= m_WidthBlackKey / 2.f;

			hitboxes[1] = std::make_unique<SDL_FRect>(secondHitbox);

			startPoint.x += m_WidthWhiteKey;
		}
		else
		{
			bounds = {
				startPoint.x - (m_WidthBlackKey / 2.f),
				startPoint.y - m_HeightWhiteKey / 2.f,
				m_WidthBlackKey,
				m_HeightBlackKey
			};

			hitboxes[0] = std::make_unique<SDL_FRect>(bounds);
		}
		m_Keys.emplace_back(keyModels[i], bounds, isWhite, std::move(hitboxes));
	}
}