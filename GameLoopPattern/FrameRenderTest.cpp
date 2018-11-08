#include "stdafx.h"
#include "FrameRenderTest.h"
#include "Player.h"
#include "Monster.h"


FrameRenderTest::FrameRenderTest()
{
}


FrameRenderTest::~FrameRenderTest()
{
}


bool FrameRenderTest::Init()
{
	//_background = new Image;
	//_background->Init(TEXT("Image/background.bmp"), WINSIZEX, WINSIZEY);
	_background = IMAGEMANAGER->AddImage(TEXT("background"), TEXT("Image/background.bmp"),
		WINSIZEX, WINSIZEY, true, RGB(0,0,0));

	IMAGEMANAGER->AddFrameImage(TEXT("Player1"), TEXT("SpriteImage/Runner.bmp"), 440, 108, 8, 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->AddFrameImage(TEXT("Monster"), TEXT("SpriteImage/Monster.bmp"), 358, 632, 2, 4, true, RGB(255, 0, 255));
	
	//GetClientRect(_hWnd, &clientRC);
	//
	//ClipCursor(&clientRC);

	player = new Player;
	monster = new Monster;


	indexBlend = 100;

	return true;
}

void FrameRenderTest::Release()
{
	//SAFE_DELETE(_background); // �̹��� �Ŵ����� ����ҋ��� �̹��� �޴����� �ҷ��ͼ� ������ �ȴ�.
	//SAFE_DELETE(player);
	//SAFE_DELETE(monster);
}

void FrameRenderTest::Update()
{
	player->Update();
	monster->Update();
	CheckRect();
}

void FrameRenderTest::Render(HDC hdc)
{
	//_background->Render(hdc, 0, 0);
	_background->AlphaRender(hdc, indexBlend);
	monster->Render(hdc);
	player->Render(hdc);
}

void FrameRenderTest::CheckRect()
{
}