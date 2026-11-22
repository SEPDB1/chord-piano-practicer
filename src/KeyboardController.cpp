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

void KeyboardController::OnMouseMotion(const SDL_FPoint& mouse)
{
	for (auto& keyView : m_View.GetKeyViews())
	{
		auto& keyModel{ keyView.GetModel() };
		bool isOverlapping{ false };

		for (auto& pHitbox : keyView.GetHitboxes())
		{
			if (SDL_PointInRectFloat(std::addressof(mouse), pHitbox.get()))
				isOverlapping = true;
		}

		const bool isSelected{ keyModel.IsSelected() };
		if (isSelected && !isOverlapping)
			keyModel.Deselect();
		else if (!isSelected && isOverlapping)
			keyModel.Select();
	}
}
