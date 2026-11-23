#include "KeyboardController.h"

KeyboardController::KeyboardController(KeyboardModel& model, KeyboardView& view)
	: m_Model{ model }
	, m_View{ view }
{
	auto& keyViews{ view.GetKeyViews() };
	m_Controllers.reserve(keyViews.size());

	for (auto& key : keyViews)
		m_Controllers.emplace_back(key.GetModel(), key);
}

void KeyboardController::Update(const SDL_FPoint& mouse, bool isLMBDown)
{
	// TO DO: fix thix messy function
	bool isMouseOverlap{ false };
	for (auto& keyController : m_Controllers)
	{
		auto& keyModel{ keyController.GetModel() };
		auto& keyView{ keyController.GetView() };
		const bool isMouseOverlapping{ keyView.IsOverlapping(mouse) };

		if (isLMBDown && isMouseOverlapping)
		{
			keyController.Press();
			keyController.StartPlaying();

			if (m_LastSelectedKey != std::addressof(keyController) && m_Model.IsPedalDown())
			{
				keyController.StopPlaying();
				keyController.StartPlaying();
			}
		}
		else
		{
			keyController.Release();

			if (!m_Model.IsPedalDown())
				keyController.StopPlaying();
		}

		if (isMouseOverlapping)
		{
			keyController.Select();
			m_LastSelectedKey = std::addressof(keyController);
			isMouseOverlap = true;
		}
		else
		{
			keyController.Deselect();
		}
	}

	if (!isMouseOverlap)
		m_LastSelectedKey = nullptr;
}

void KeyboardController::OnPedalUp()
{
	m_Model.RaisePedal();
}

void KeyboardController::OnPedalDown()
{
	m_Model.LowerPedal();
}
