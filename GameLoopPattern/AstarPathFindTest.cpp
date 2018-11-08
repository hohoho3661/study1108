#include "stdafx.h"
#include "AstarPathFindTest.h"
#include "AstarTest.h"

AstarPathFindTest::AstarPathFindTest()
{
}

AstarPathFindTest::~AstarPathFindTest()
{
}

bool AstarPathFindTest::Init()
{
	pTest = new AstarTest;
	pTest->Init();



	return true;
}

void AstarPathFindTest::Release()
{
	delete pTest;
}

void AstarPathFindTest::Update()
{
	pTest->Update();
}

void AstarPathFindTest::Render(HDC hdc)
{
	pTest->Render(hdc);
}
