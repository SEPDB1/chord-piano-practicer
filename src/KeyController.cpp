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
	AudioManager::GetInstance().PlayNote(m_Model.GetMidi());
}

void KeyController::Release()
{
	if (!m_Model.IsPressed())
		return;

	m_Model.Release();
	AudioManager::GetInstance().StopNote(m_Model.GetMidi());
}

void KeyController::Select()
{
	if (!m_Model.IsSelected())
		m_Model.Select();
}

void KeyController::Deselect()
{
	if (m_Model.IsSelected())
		m_Model.Deselect();
}

KeyModel& KeyController::GetModel() const
{
	return m_Model;
}

KeyView& KeyController::GetView() const
{
	return m_View;
}
