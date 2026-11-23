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
	for (auto& keyController : m_Controllers)
	{
		auto& keyModel{ keyController.GetModel() };
		auto& keyView{ keyController.GetView() };
		const bool isMouseOverlapping{ keyView.IsOverlapping(mouse) };

		if (isMouseOverlapping)
			keyController.Select();
		else
			keyController.Deselect();

		if (isLMBDown && isMouseOverlapping)
			keyController.Press();
		else
			keyController.Release();
	}
}
