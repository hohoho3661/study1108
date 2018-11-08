#include "stdafx.h"
#include "SpaceShip.h"
#include "ProgressBar.h"



SpaceShip::SpaceShip()
{
}


SpaceShip::~SpaceShip()
{
}

bool SpaceShip::Init()
{	
	image = IMAGEMANAGER->findImage(TEXT("Player"));
		
	pt.x = WINSIZEX / 2;
	pt.y = WINSIZEY - 100;

	image->SetX(pt.x);
	image->SetY(pt.y);

	speed = 5.f;

	//curHP = maxHP = 100; // 체력 설정
	curHP = 100;
	maxHP = 100;

	hpBar = new ProgressBar;
	hpBar->Init(image->GetX(), image->GetY() - 20, 52, 10);
	hpBar->SetGauge(curHP, maxHP);

	
	return true;
}

void SpaceShip::Release()
{
	hpBar->Release();
}

void SpaceShip::Update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		pt.x -= speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		pt.x += speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		pt.y -= speed;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		pt.y += speed;
	}

	rc = RectMakeCenter(pt.x, pt.y, image->GetWidth(), image->GetHeight());

	hpBar->SetX(rc.left);
	hpBar->SetY(rc.top - 20);
	hpBar->SetGauge(curHP, maxHP);
	hpBar->Update();
}

void SpaceShip::Render(HDC hdc)
{
	image->Render(hdc, rc.left, rc.top);

	hpBar->Render(hdc);
}
