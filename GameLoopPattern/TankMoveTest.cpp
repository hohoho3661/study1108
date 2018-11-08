#include "stdafx.h"
#include "TankMoveTest.h"
#include "TankMap.h"
#include "Tank.h"

TankMoveTest::TankMoveTest()
{
}

TankMoveTest::~TankMoveTest()
{
}

bool TankMoveTest::Init()
{
	tankMap = new TankMap;
	assert(tankMap != NULL);

	if (!tankMap->Load())
		return false;

	tank = new Tank;
	assert(tank != NULL);

	tank->SetTankMap(tankMap);
	
	return true;
}

void TankMoveTest::Release()
{
	SAFE_DELETE(tankMap);
	SAFE_DELETE(tank);
}

void TankMoveTest::Update()
{
	tank->Update();
}

void TankMoveTest::Render(HDC hdc)
{
	tankMap->Render(hdc);
	tank->Render(hdc);
}
