#pragma once
#include "IObserver.h"
#include "KeyboardModel.h"
#include "KeyView.h"
#include <SDL3/SDL_rect.h>

class KeyboardView final : public IObserver
{
public:
	explicit KeyboardView(KeyboardModel& model, const SDL_FPoint& center);
	~KeyboardView() noexcept;
	KeyboardView(const KeyboardView& other) = default;
	KeyboardView& operator=(const KeyboardView& other) = default;
	KeyboardView(KeyboardView&& other) = default;
	KeyboardView& operator=(KeyboardView&& other) = default;

	void Render() const;

	void OnNotify(uint8_t eventId) override;

private:
	std::vector<KeyView> m_Keys{};
	KeyboardModel& m_Model;
	SDL_FPoint m_Center{};

	constexpr static float m_WidthWhiteKey{ 85.f };
	constexpr static float m_HeightWhiteKey{ 330.f };
	constexpr static float m_WidthBlackKey{ m_WidthWhiteKey / 2.f };
	constexpr static float m_HeightBlackKey{ 2.f * m_HeightWhiteKey / 3.f };

	void CreateKeys();
};