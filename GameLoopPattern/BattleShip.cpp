#include "stdafx.h"
#include "BattleShip.h"

BattleShip::BattleShip()
{
}

BattleShip::~BattleShip()
{
}

bool BattleShip::Init(const string imageName, int x, int y)
{
	image = IMAGEMANAGER->findImage(imageName);
	if (image == NULL)
		return false;
	
	this->x = x;
	this->y = y;

	angle = 0.f;
	speed = 0.f;

	rc = RectMakeCenter(this->x, this->y, image->GetFrameWidth(), image->GetFrameHeight());
	
	return true;
}

void BattleShip::Release()
{
}

void BattleShip::Update()
{
	Input();
	Move();
}

void BattleShip::Render(HDC hdc)
{
	Draw(hdc);
}

void BattleShip::Draw(HDC hdc)
{
	image->FrameRender(hdc, rc.left, rc.top);
#if defined(_DEBUG)
	TCHAR szTemp[128] = { 0, };
	_stprintf(szTemp, TEXT("Angle : %d, Speed : %3.2f"),
		int(angle * 100 / PI), speed);
	TextOut(hdc, rc.left, rc.top - 15, szTemp, _tcslen(szTemp));
#endif//
}

void BattleShip::Input()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (angle >= PI2)
			angle -= PI2;

		angle += 0.05f; // 회전하는 정도를 설정
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (angle <= 0)
			angle += PI2;
		angle -= 0.05f;
	}
}

void BattleShip::Move()
{
	int			frame;
	float		_angle;

	_angle = angle + (PI / 16.f);			// 자료형의 크기 16을 보정치로 줌.       플롯형이니까 16
	frame = int(_angle / (PI2 / 16.f));
	image->SetFrameX(frame);
	
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveSpeed = elapsedTime * 100;

	x += cosf(angle) * speed * moveSpeed;
	y += -sinf(angle) * speed * moveSpeed;

	rc = RectMakeCenter(x, y, image->GetFrameWidth(), image->GetFrameHeight());
}