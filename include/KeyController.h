#pragma once
#include "KeyModel.h"
#include "KeyView.h"

class KeyController final
{
public:
	explicit KeyController(KeyModel& model, KeyView& view);

	void Press();
	void Release();
	void Select();
	void Deselect();
	void StartPlaying();
	void StopPlaying();

	const KeyModel& GetModel() const;
	const KeyView& GetView() const;

private:
	KeyModel& m_Model;
	KeyView& m_View;
};