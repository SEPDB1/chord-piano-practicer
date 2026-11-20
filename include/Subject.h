#pragma once
#include "IObserver.h"

class Subject
{
public:
	void SetObserver(IObserver* pObserver)
	{
		m_pObserver = pObserver;
	}

protected:
	virtual ~Subject() = default;

	void Notify(uint8_t eventId)
	{
		if (m_pObserver)
			m_pObserver->OnNotify(eventId);
	}

private:
	IObserver* m_pObserver{};
};