#pragma once
#include "KeyModel.h"
#include "KeyView.h"

class KeyController final
{
public:
	explicit KeyController(KeyModel& model, KeyView& view);



private:
	KeyModel& m_Model;
	KeyView& m_View;
};