#pragma once
#include <cstdint>
#include "Utils.h"

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

	inline constexpr static Note::Midi min{ 21 };
	inline constexpr static Note::Midi max{ 108 };

	inline constexpr static Utils::Color4ub keyColors[12]
	{
		{  0, 128, 255, 255}, // A     Blue
		{  0,   0, 255, 255}, // A#/Bb Indigo
		{128,   0, 255, 255}, // B     Violet
		{255,   0,   0, 255}, // C     Red
		{255,  64,   0, 255}, // C#/Db Red-Orange
		{255, 128,   0, 255}, // D     Orange
		{255, 191,   0, 255}, // D#/Eb Yellow-Orange
		{255, 255,   0, 255}, // E     Yellow
		{128, 255,   0, 255}, // F     Yellow-Green
		{  0, 255,   0, 255}, // F#/Gb Green
		{  0, 255, 128, 255}, // G     Green-Cyan
		{  0, 255, 255, 255}  // G#/Ab Cyan
	};

	/*
	 Corresponds the MIDI value to a piano key?
	*/
	inline constexpr bool IsInRange(Midi value)
	{
		return min < value && value < max;
	}

	/*
	 Shifts the MIDI value to the first octave (A0 -> G#1/Ab1)
	*/
	inline constexpr Midi Normalise(Midi value)
	{
		return (value - min) % 12;
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

	inline constexpr Utils::Color4ub MidiToColor(Midi value)
	{
		return keyColors[Normalise(value)];
	}
};