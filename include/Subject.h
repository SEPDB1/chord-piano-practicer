#pragma once
#include "IObserver.h"
#include <cstdint>

class Subject
{
public:
	void SetObserver(IObserver* pObserver)
	{
		m_pObserver = pObserver;
	}

	void RemoveObserver()
	{
		m_pObserver = nullptr;
	}

protected:
	Subject() = default;
	virtual ~Subject() noexcept = default;

	void Notify(uint8_t eventId)
	{
		if (m_pObserver)
			m_pObserver->OnNotify(eventId);
	}

private:
	IObserver* m_pObserver{};
};