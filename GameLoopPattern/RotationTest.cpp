#include "stdafx.h"
#include "RotationTest.h"
#include "BattleShip.h"

RotationTest::RotationTest()
{
}


RotationTest::~RotationTest()
{
}

bool RotationTest::Init()
{
	IMAGEMANAGER->AddImage(TEXT("Background10"), TEXT("Image/background.bmp"), WINSIZEX, WINSIZEY, true, COLOR_M);

	Image* ship = IMAGEMANAGER->AddFrameImage(TEXT("BattleShip"), TEXT("SpriteImage/battle.bmp"), 0, 0, 1536, 79, 16, 1, true, COLOR_M);

	if (NULL == ship)
	{
		return false;
	}

	pShip = new BattleShip();
	assert(pShip != NULL);

	pShip->Init(TEXT("BattleShip"), WINSIZEX / 2, WINSIZEY / 2);
		
	return true;


}

void RotationTest::Release()
{
}

void RotationTest::Update()
{
	pShip->Update();
}

void RotationTest::Render(HDC hdc)
{
	IMAGEMANAGER->Render(TEXT("Background10"), hdc,0,0);
	pShip->Render(hdc);
	//IMAGEMANAGER->FrameRender(TEXT("BattleShip"), hdc, 500, 500);
}
