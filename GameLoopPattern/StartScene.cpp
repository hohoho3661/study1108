#include "stdafx.h"
#include "StartScene.h"
#include "Button.h"



StartScene::StartScene()
{
}


StartScene::~StartScene()
{
}

bool StartScene::Init()
{
	IMAGEMANAGER->findImage(TEXT("StartImage"));
//	selectButton = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);

	IMAGEMANAGER->AddFrameImage(TEXT("Button1"), TEXT("Image/Button1.bmp"), 0, 0, 122, 62, 1, 2, false, RGB(255, 255, 255));

	pButton = new Button;
	assert(pButton != NULL);

	pButton->Init(TEXT("Button1"), WINSIZEX / 2, WINSIZEY / 2, 
		PointMake(0, 1), PointMake(0, 0), cbSceneChange);


	return true;
}

void StartScene::Release()
{
	SAFE_DELETE(pButton);
}

void StartScene::Update()
{


	pButton->Update();

	//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	//{
	//	GetCursorPos(&_ptMouse);				// 전체화면기준
	//	ScreenToClient(_hWnd, &_ptMouse);		// 클라이언트 기준으로 바꿔줌

	//	if (PtInRect(&selectButton, _ptMouse))
	//	{
	//		SCENEMANAGER->ChangeScene("Loading");
	//	}
	//}
}

void StartScene::Render(HDC hdc)
{
	IMAGEMANAGER->Render(TEXT("StartImage"), hdc);
	//Rectangle(hdc, selectButton.left, selectButton.top, selectButton.right, selectButton.bottom);	
	pButton->Render(hdc);
}

void StartScene::cbSceneChange()
{
	SCENEMANAGER->ChangeScene(TEXT("Loading"));
}



// 버튼은 ,,, 실행하기위한 직접정인 정보는 x

// 함수포인터를 실행하도록만

// 여기서는 cbSceneChange()이다.