#pragma once
#include <cstdint>

namespace Utils
{
	struct Color final
	{
		uint8_t r{};
		uint8_t g{};
		uint8_t b{};
		uint8_t a{};

		Color() = default;
		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) 
			: r{ r }, g{ g }, b{ b }, a{ a } {}
	};
}