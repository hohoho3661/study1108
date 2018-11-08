#include "stdafx.h"
#include "CameraTest.h"
#include "Player.h"


CameraTest::CameraTest()
{
}


CameraTest::~CameraTest()
{
}

bool CameraTest::Init()
{
	_background = IMAGEMANAGER->AddImage(TEXT("background"), TEXT("Image/11.bmp"),
		2323, 1082, false, RGB(0, 0, 0));

	IMAGEMANAGER->AddFrameImage(TEXT("Player"), TEXT("SpriteImage/시바달리기.bmp"), 440, 108, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->AddFrameImage(TEXT("Monster"), TEXT("SpriteImage/Monster.bmp"), 358, 632, 2, 4, true, RGB(255, 0, 255));


	_player = new Player;

	_rcClient = { 0,0,WINSIZEX,WINSIZEY };
	_rcWorld = { 0,0,2323,1082 };

	if (CAMERA->Init(_player->GetPos(), _rcClient, _rcWorld) == false)
	{
		return false;
	}

	return true;
}

void CameraTest::Release()
{
	SAFE_DELETE(_player);
}

void CameraTest::Update()
{
	_player->Update();

	CAMERA->Update();
}

void CameraTest::Render(HDC hdc)
{
	//Rectangle(hdc, _rcClient.left, _rcClient.top, _rcClient.right, _rcClient.bottom);
	// 랜더링할때 카메라의 포지션을 플레이어의 이동위치만큼 빼줘서 랜더링

	//CAMERA->Update();
	_background->Render(hdc, 0, 0, CAMERA->getPosition()->x,
		CAMERA->getPosition()->y,
		WINSIZEX,WINSIZEY);
	_player->Render(hdc);
}
