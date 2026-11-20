#pragma once
class IObserver
{
public:
	virtual ~IObserver() {}
	virtual void OnNotify(uint8_t eventId) = 0;
};