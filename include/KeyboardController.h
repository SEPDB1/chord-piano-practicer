#pragma once
#include <vector>
#include "KeyController.h"
#include "KeyboardModel.h"
#include "KeyboardView.h"

class KeyboardController final
{
public:
	explicit KeyboardController(KeyboardModel& model, KeyboardView& view);

	void OnMouseMotion(const SDL_FPoint& mouse);

private:
	std::vector<KeyController> m_Controllers{};
	KeyboardModel& m_Model;
	KeyboardView& m_View;
};