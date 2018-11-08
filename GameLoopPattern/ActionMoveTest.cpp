#include "stdafx.h"
#include "ActionMoveTest.h"
#include "Action.h"


ActionMoveTest::ActionMoveTest()
{
}


ActionMoveTest::~ActionMoveTest()
{
}

bool ActionMoveTest::Init()
{
	background = IMAGEMANAGER->findImage(TEXT("InGameImage"));
	assert(background != NULL);


	action = new Action;

	action->Init();

	actionImage = IMAGEMANAGER->findImage(TEXT("rocket"));
	assert(actionImage != NULL);


	actionImage->SetX(100);	// 출발지점
	actionImage->SetY(100); //

	x = 800;	// 도착지점
	y = 500;	//

	action->MoveTo(actionImage, x, y, 20.f);

	return true;
}

void ActionMoveTest::Release()
{
}

void ActionMoveTest::Update()
{
	action->Update();
}

void ActionMoveTest::Render(HDC hdc)
{
	background->Render(hdc);
	actionImage->Render(hdc, actionImage->GetX(), actionImage->GetY());
}
