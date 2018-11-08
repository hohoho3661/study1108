#pragma once
#include "GameNode.h"

class PixelCollisionTest : public GameNode
{
	Image * _mountain;
	Image*	_ball;

	RECT	_rc;
	float	_x, _y;
	int		_probY;

public:
	PixelCollisionTest();
	~PixelCollisionTest();

	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	void PixelCheck(RECT& _rc, Image* _map,COLORREF); // 충돌대상, 비교할곳, RGB마젠타
};

