#pragma once
#include "Note.h"
#include "Subject.h"
#include "SdbmHash.h"

class KeyModel final : public Subject 
{
public:
	KeyModel() = default;
	KeyModel(Note::Midi midi)
		: m_Midi{ midi }
	{
	}

	void Press()
	{
		m_IsPressed = true;
	}

	void Release()
	{
		m_IsPressed = false;
	}

	void Select()
	{
		m_IsSelected = true;
	}

	void Deselect()
	{
		m_IsSelected = false;
	}

	void StartPlaying()
	{
		m_IsPlaying = true;
	}

	void StopPlaying()
	{
		m_IsPlaying = false;
	}

	Note::Midi GetMidi() const
	{
		return m_Midi;
	}

	bool IsPressed() const
	{
		return m_IsPressed;
	}

	bool IsSelected() const
	{
		return m_IsSelected;
	}

	bool IsPlaying() const
	{
		return m_IsPlaying;
	}

private:
	Note::Midi m_Midi{};
	bool m_IsPressed{};
	bool m_IsSelected{};
	bool m_IsPlaying{};
};