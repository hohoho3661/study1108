#include "stdafx.h"
#include "PixelCollisionTest.h"



PixelCollisionTest::PixelCollisionTest()
{
}


PixelCollisionTest::~PixelCollisionTest()
{
}

bool PixelCollisionTest::Init()
{
	_mountain = IMAGEMANAGER->AddImage(TEXT("Ground"), TEXT("Image/mountain.bmp"), WINSIZEX, WINSIZEY, true, COLOR_M);

	_ball = IMAGEMANAGER->AddImage(TEXT("Ball"), TEXT("Image/ball.bmp"), 60, 60, true, COLOR_M);

	_x = WINSIZEX/2 - 150;
	_y = WINSIZEY/2 + 400;

	_rc = RectMakeCenter(_x, _y, _ball->GetWidth(), _ball->GetHeight());

	//픽셀충돌을 처리할 축 (탐사 축)
	_probY = _y + _ball->GetHeight() / 2; // 볼에 중심에서 반지름만큼을 더한.

	return true;
}

void PixelCollisionTest::Release()
{
}

void PixelCollisionTest::Update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		_x -= 3;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		_x += 3;

	if (_x < _ball->GetWidth()/2)
		_x = _ball->GetWidth()/2;
	if (_x > WINSIZEX - _ball->GetWidth()/2)
		_x = WINSIZEX - _ball->GetWidth()/2;


	_rc = RectMakeCenter(_x, _y, _ball->GetWidth(), _ball->GetHeight());
	


	//========================================================================================
	_probY = _y + _ball->GetHeight() / 2;

	for (int i = _probY - 100; i < _probY + 100; ++i) // 아래위로 넉넉히 100피스정도 검사함.
	{
		COLORREF color = GetPixel(_mountain->GetMemDC(), _x, i); // GetPixel 픽셀 하나하나의 값을 가져옴.

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_y = i - _ball->GetHeight() / 2;
			break;
		}
	}
	//========================================================================================

}

void PixelCollisionTest::Render(HDC hdc)
{
	_mountain->Render(hdc);

	_ball->Render(hdc, _rc.left, _rc.top);
}

void PixelCollisionTest::PixelCheck(RECT& _rc, Image* _map, COLORREF) // 충돌대상, 비교할곳, RGB마젠타
{
	//========================================================================================
	_probY = _y + _ball->GetHeight() / 2;

	for (int i = _probY - 100; i < _probY + 100; ++i) // 아래위로 넉넉히 100피스정도 검사함.
	{
		COLORREF color = GetPixel(_map->GetMemDC(), _x, i); // GetPixel 픽셀 하나하나의 값을 가져옴.

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 255 && g == 0 && b == 255))
		{
			_y = i - _ball->GetHeight() / 2;
			break;
		}
	}
	//========================================================================================
}
