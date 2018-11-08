#include "stdafx.h"
#include "InGameScene.h"
#include "SpaceShip.h"
#include "Enemy.h"


InGameScene::InGameScene()
{
}


InGameScene::~InGameScene()
{
}

bool InGameScene::Init()
{	
	IMAGEMANAGER->findImage(TEXT("InGameImage"));

	ship = new SpaceShip;
	ship->Init();

	enemy = new Enemy;
	enemy->Init();
	
	return true;
}

void InGameScene::Release()
{
	SAFE_DELETE(ship);
	SAFE_DELETE(enemy);
}

void InGameScene::Update()
{
	ship->Update();
	enemy->Update();
}

void InGameScene::Render(HDC hdc)
{
	IMAGEMANAGER->Render(TEXT("InGameImage"), hdc);
	ship->Render(hdc);
	enemy->Render(hdc);
}
