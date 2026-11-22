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
		if (m_IsPressed)
			return;

		m_IsPressed = true;
		Notify(MakeSdbmHash("OnPress"));
	}

	void Release()
	{
		if (!m_IsPressed)
			return;

		m_IsPressed = false;
		Notify(MakeSdbmHash("OnRelease"));
	}

	void Select()
	{
		if (m_IsSelected)
			return;

		m_IsSelected = true;
		Notify(MakeSdbmHash("OnSelect"));
	}

	void Deselect()
	{
		if (!m_IsSelected)
			return;

		m_IsSelected = false;
		Notify(MakeSdbmHash("OnDeselect"));
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

private:
	Note::Midi m_Midi{};
	bool m_IsPressed{};
	bool m_IsSelected{};
};