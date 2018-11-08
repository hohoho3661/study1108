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

	//�ȼ��浹�� ó���� �� (Ž�� ��)
	_probY = _y + _ball->GetHeight() / 2; // ���� �߽ɿ��� ��������ŭ�� ����.

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

	for (int i = _probY - 100; i < _probY + 100; ++i) // �Ʒ����� �˳��� 100�ǽ����� �˻���.
	{
		COLORREF color = GetPixel(_mountain->GetMemDC(), _x, i); // GetPixel �ȼ� �ϳ��ϳ��� ���� ������.

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

void PixelCollisionTest::PixelCheck(RECT& _rc, Image* _map, COLORREF) // �浹���, ���Ұ�, RGB����Ÿ
{
	//========================================================================================
	_probY = _y + _ball->GetHeight() / 2;

	for (int i = _probY - 100; i < _probY + 100; ++i) // �Ʒ����� �˳��� 100�ǽ����� �˻���.
	{
		COLORREF color = GetPixel(_map->GetMemDC(), _x, i); // GetPixel �ȼ� �ϳ��ϳ��� ���� ������.

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
