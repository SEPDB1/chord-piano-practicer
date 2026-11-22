#include "KeyboardController.h"

KeyboardController::KeyboardController(KeyboardModel& model, KeyboardView& view)
	: m_Model{ model }
	, m_View{ view }
{
	auto& keyViews{ view.GetKeyViews() };
	m_Controllers.reserve(keyViews.size());

	for (auto& keyView : keyViews)
		m_Controllers.emplace_back(keyView.GetModel(), keyView);
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

void KeyboardController::OnMouseMotion(const SDL_FPoint& mouse)
{
	for (auto& keyView : m_View.GetKeyViews())
	{
		auto& keyModel{ keyView.GetModel() };
		const bool isOverlapping{ keyView.IsOverlapping(mouse) };
		const bool isSelected{ keyModel.IsSelected() };

		if (isSelected && !isOverlapping)
			keyModel.Deselect();
		else if (!isSelected && isOverlapping)
			keyModel.Select();
	}
}

void KeyboardController::OnMouseUp()
{
	for (auto& keyModel : m_Model.GetKeys())
	{
		if (keyModel.IsPressed())
			keyModel.Release();
	}
}

void KeyboardController::OnMouseDown(const SDL_FPoint& mouse)
{
	for (auto& keyView : m_View.GetKeyViews())
	{
		auto& keyModel{ keyView.GetModel() };

		if (!keyModel.IsPressed() && keyView.IsOverlapping(mouse))
			keyModel.Press();
	}
}
