#pragma once
#include <cstdint>
#include <ostream>
#include <SDL3/SDL_rect.h>

namespace Utils
{
	/*
	 A color struct having a 1 byte R, G, B and A component 
	*/
	struct Color4ub final
	{
		uint8_t r{};
		uint8_t g{};
		uint8_t b{};
		uint8_t a{};

		constexpr Color4ub() = default;

		constexpr Color4ub(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255)
			: r{ r }, g{ g }, b{ b }, a{ a }
		{
		}

		constexpr bool operator==(const Color4ub& other) const = default;

		friend std::ostream& operator<<(std::ostream& os, const Color4ub& other)
		{
			return os 
				<< "Color4ub = { " 
				<< static_cast<int>(other.r) << ", " 
				<< static_cast<int>(other.g) << ", " 
				<< static_cast<int>(other.b) << ", " 
				<< static_cast<int>(other.a) << " }\n";
		}
	};
	/*
	 Return a rectangle that is scaled by margin (in # of pixels) on every side
	*/
	inline SDL_FRect ScaleByPixels(const SDL_FRect& other, float margin)
	{
		return SDL_FRect{
			other.x - margin,
			other.y - margin,
			other.w + margin * 2.f,
			other.h + margin * 2.f
		};
	}
}