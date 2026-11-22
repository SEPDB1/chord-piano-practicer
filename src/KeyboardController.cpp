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
	for (auto& keyView : m_View.GetKeyViews())
	{
		auto& keyModel{ keyView.GetModel() };
		const bool isMouseOverlapping{ keyView.IsOverlapping(mouse) };

		if (isMouseOverlapping)
			keyModel.Select();
		else
			keyModel.Deselect();

		if (isLMBDown && isMouseOverlapping)
			keyModel.Press();
		else
			keyModel.Release();
	}
}
