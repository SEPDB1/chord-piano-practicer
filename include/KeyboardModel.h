#pragma once
#include "Subject.h"
#include "KeyModel.h"
#include <vector>

class KeyboardModel final : public Subject
{
public:
	explicit KeyboardModel(uint8_t startMidi, uint8_t nrOctaves = 1)
		: m_NrOctaves{ nrOctaves }
	{
		m_Keys.reserve(nrOctaves * 12);

		for (uint8_t i{ 0 }; i < nrOctaves * 12; ++i)
			m_Keys.emplace_back(startMidi + i);
	}

	void LowerPedal()
	{
		m_IsPedalDown = true;
	}

	void RaisePedal()
	{
		m_IsPedalDown = false;
	}

	const std::vector<KeyModel>& GetKeys() const
	{
		return m_Keys;
	}

	std::vector<KeyModel>& GetKeys()
	{
		return m_Keys;
	}

	bool IsPedalDown() const
	{
		return m_IsPedalDown;
	}

private:
	std::vector<KeyModel> m_Keys{};
	const uint8_t m_NrOctaves{ 1 };
	bool m_IsPedalDown{ false };
};