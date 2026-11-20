#pragma once
#include <cstdint>

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

		bool operator==(const Color4ub& other) const = default;
	};

	/*
	 An enumeration that represents every possible note inside an octave by letter
	*/
	enum class NoteLetter : uint8_t
	{
		C,
		CSharp,
		DFlat,
		D,
		DSharp,
		EFlat,
		E,
		F,
		FSharp,
		GFlat,
		G,
		GSharp,
		AFlat,
		A,
		ASharp,
		BFlat,
		B
	};

	/*
	 A physical note on an instrument
	*/
	struct Note final
	{
		NoteLetter letter;
		uint8_t octave;

		bool operator==(const Note& other) const = default;
	};
}