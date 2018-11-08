#pragma once
#include "SingleTon.h"

class Timer;

class TimeManager : public SingletonBase<TimeManager>
{
private:
	Timer * _timer;

public:
	TimeManager();
	~TimeManager();

	bool Init();
	void Release();
	void Update(float lock = 0.0f);
	void Render(HDC hdc);

	float getElapsedTime() const; // ����� �ð�
	float getWorldTime() const;

};

