#include "stdafx.h"
#include "MainGame.h"

#include "MovieTest.h"
#include "ImageCropTest.h"
#include "RenderTest.h"
#include "FrameRenderTest.h"
#include "TrigonometricTest.h"
#include "StalkerTest.h"
#include "AnimationTest.h"
#include "CameraTest.h"
#include "PixelCollisionTest.h"
#include "EffectTest.h"
#include "AlphaRenderTest.h"
#include "RotationTest.h"
#include "MapTool.h"
#include "TankMoveTest.h"
#include "ActionMoveTest.h"
#include "AstarPathFindTest.h"


#include "StartScene.h"
#include "InGameScene.h"
#include "LoadingScene.h"

MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}



bool MainGame::Init() // 초기화
{
	GameNode::Init(true);

	//===================================

	// 여기서 이미지 메니저를 초기화 하자.
	IMAGEMANAGER->Init();

	// 씬매니저를 초기화 하고 ... Scene을 추가
	SCENEMANAGER->Init();
	//
	IMAGEMANAGER->AddImage(TEXT("StartImage"), TEXT("Image/111.bmp"), 1372, 772, false, RGB(0, 0, 0));
	IMAGEMANAGER->AddImage(TEXT("InGameImage"), TEXT("Image/background.bmp"), WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
//	IMAGEMANAGER->AddImage(TEXT("Player"), TEXT("Image/rocket.bmp"), 52, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->AddFrameImage(TEXT("UFO"), TEXT("Image/ufo.bmp"), 0, 0, 530, 32, 10, 1, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("rocket"), TEXT("Image/rocket.bmp"), 52, 64, true, COLOR_M);

		


	// 씬 추가
	SCENEMANAGER->AddScene(TEXT("Start"), new StartScene);

	SCENEMANAGER->AddScene(TEXT("Loading"), new LoadingScene);

	SCENEMANAGER->AddScene(TEXT("InGame"), new InGameScene);

	// Test Scene

	SCENEMANAGER->AddScene(TEXT("tank"), new TankMoveTest);

	SCENEMANAGER->AddScene(TEXT("MapTool"), new MapTool);

	SCENEMANAGER->AddScene(TEXT("Action"), new ActionMoveTest);

	SCENEMANAGER->AddScene(TEXT("Astar"), new AstarPathFindTest);




	// 첫 씬 설정
	SCENEMANAGER->ChangeScene(TEXT("Astar"));

//#if defined(_MAPTOOL_TEST)
//	SCENEMANAGER->ChangeScene(TEXT("MapTool"));
//#else
//	SCENEMANAGER->ChangeScene(TEXT("Start"));
//#endif//	

	//===================================

	return true;
}

void MainGame::Release() // 해제
{
	GameNode::Release();
	//==================================
	
	//IMAGEMANAGER->Release();
	//SCENEMANAGER->Release();

	//==================================
}

void MainGame::Update() // 변동
{
	GameNode::Update();
	//==================================
#if defined(_MAPTOOL_TEST)
	if (KEYMANAGER->isOnceKeyDown(VK_F3))
	{
		SCENEMANAGER->ChangeScene(TEXT("tank"));
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F4))
	{
		SCENEMANAGER->ChangeScene(TEXT("MapTool"));
	}
#endif//


	SCENEMANAGER->Update();
	//==================================

}

void MainGame::Render(HDC hdc) // 그리기 ( 화면 출력 ) // 랜더링작업을 백버퍼에 프래임단위로 1/10초마다 한번씩 화면에 뿌려줌
{
	//GameNode::Render(hdc);

	if (_hWndAvi)
	{

	}
	else
	{
		HDC	backDC = (this->GetBackBuffer())->GetMemDC();
		PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
		//============================
		// 모든작업은 여기 안에서 작업.

		SCENEMANAGER->Render(backDC);


		//============================
		this->GetBackBuffer()->Render(hdc, 0, 0);
	}
}