#pragma once
#include "IObserver.h"
#include "Utils.h"
#include "KeyModel.h"
#include <array>
#include <memory>
#include <SDL3/SDL_rect.h>

class KeyView final : public IObserver
{
public:
	explicit KeyView(KeyModel& model, const SDL_FRect& bounds, bool isWhite, std::array<std::unique_ptr<SDL_FRect>, 2> hitboxes);
	~KeyView() noexcept;
	KeyView(const KeyView&) = delete;
	KeyView& operator=(const KeyView&) = delete;
	KeyView(KeyView&&) noexcept = default;
	KeyView& operator=(KeyView&&) noexcept = default;

	void Render() const;

	void OnNotify(uint8_t eventId) override;

	bool IsWhite() const;

private:
	KeyModel& m_Model;
	SDL_FRect m_BorderBounds{};
	SDL_FRect m_InsideBounds{};
	std::array<std::unique_ptr<SDL_FRect>, 2> m_Hitboxes{};
	bool m_IsWhite{};

	constexpr static Utils::Color4ub m_White{ 255, 255, 255 };
	constexpr static Utils::Color4ub m_Black{ 0, 0, 0 };
	constexpr static float m_BorderSize{ 3.f };

};