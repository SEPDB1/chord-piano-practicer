#include "KeyController.h"
#include "AudioManager.h"

KeyController::KeyController(KeyModel& model, KeyView& view)
	: m_Model{ model }
	, m_View{ view }
{
}

void KeyController::Press()
{
	if (m_Model.IsPressed())
		return;

	m_Model.Press();
}

void KeyController::Release()
{
	if (!m_Model.IsPressed())
		return;

	m_Model.Release();
}

void KeyController::Select()
{
	if (m_Model.IsSelected())
		return;

	m_Model.Select();
}

void KeyController::Deselect()
{
	if (!m_Model.IsSelected())
		return;

	m_Model.Deselect();
}

void KeyController::StartPlaying()
{
	if (m_Model.IsPlaying())
		return;
	
	AudioManager::GetInstance().PlayNote(m_Model.GetMidi());
	m_Model.StartPlaying();
}

void KeyController::StopPlaying()
{
	if (!m_Model.IsPlaying())
		return;

	AudioManager::GetInstance().StopNote(m_Model.GetMidi());
	m_Model.StopPlaying();
}

const KeyModel& KeyController::GetModel() const
{
	return m_Model;
}

const KeyView& KeyController::GetView() const
{
	return m_View;
}
