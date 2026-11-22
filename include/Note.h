#pragma once
#include <cstdint>
namespace Note
{
	using Midi = uint8_t;

	/*
	 An enumeration that represents every possible note inside an octave by letter
	*/
	enum class Letter : uint8_t
	{
		C, D, E, F, G, A, B
	};

	enum class Accidental : int8_t
	{
		DoubleFlat = -2,
		Flat = -1,
		Natural = 0,
		Sharp = 1,
		DoubleSharp = 2
	};

	inline static constexpr Note::Midi m_Min{ 21 };
	inline static constexpr Note::Midi m_Max{ 108 };

	/*
	 Corresponds the MIDI value to a piano key?
	*/
	inline constexpr bool IsInRange(Midi value)
	{
		return m_Min < value && value < m_Max;
	}

	/*
	 Shifts the MIDI value to the first octave (A0 -> G#1/Ab1)
	*/
	inline constexpr Midi Normalise(Midi value)
	{
		return (value - m_Min) % 12;
	}

	/*
	 Is the piano key corresponding with the MIDI value white?
	*/
	inline constexpr bool IsWhite(Midi value)
	{
		switch (Normalise(value))
		{
		case 1: case 4: case 6: case 9: case 11:
			return false;
		default:
			return true;
		}
	}
};