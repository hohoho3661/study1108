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



bool MainGame::Init() // �ʱ�ȭ
{
	GameNode::Init(true);

	//===================================

	// ���⼭ �̹��� �޴����� �ʱ�ȭ ����.
	IMAGEMANAGER->Init();

	// ���Ŵ����� �ʱ�ȭ �ϰ� ... Scene�� �߰�
	SCENEMANAGER->Init();
	//
	IMAGEMANAGER->AddImage(TEXT("StartImage"), TEXT("Image/111.bmp"), 1372, 772, false, RGB(0, 0, 0));
	IMAGEMANAGER->AddImage(TEXT("InGameImage"), TEXT("Image/background.bmp"), WINSIZEX, WINSIZEY, false, RGB(0, 0, 0));
//	IMAGEMANAGER->AddImage(TEXT("Player"), TEXT("Image/rocket.bmp"), 52, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->AddFrameImage(TEXT("UFO"), TEXT("Image/ufo.bmp"), 0, 0, 530, 32, 10, 1, true, COLOR_M);

	IMAGEMANAGER->AddImage(TEXT("rocket"), TEXT("Image/rocket.bmp"), 52, 64, true, COLOR_M);

		


	// �� �߰�
	SCENEMANAGER->AddScene(TEXT("Start"), new StartScene);

	SCENEMANAGER->AddScene(TEXT("Loading"), new LoadingScene);

	SCENEMANAGER->AddScene(TEXT("InGame"), new InGameScene);

	// Test Scene

	SCENEMANAGER->AddScene(TEXT("tank"), new TankMoveTest);

	SCENEMANAGER->AddScene(TEXT("MapTool"), new MapTool);

	SCENEMANAGER->AddScene(TEXT("Action"), new ActionMoveTest);

	SCENEMANAGER->AddScene(TEXT("Astar"), new AstarPathFindTest);




	// ù �� ����
	SCENEMANAGER->ChangeScene(TEXT("Astar"));

//#if defined(_MAPTOOL_TEST)
//	SCENEMANAGER->ChangeScene(TEXT("MapTool"));
//#else
//	SCENEMANAGER->ChangeScene(TEXT("Start"));
//#endif//	

	//===================================

	return true;
}

void MainGame::Release() // ����
{
	GameNode::Release();
	//==================================
	
	//IMAGEMANAGER->Release();
	//SCENEMANAGER->Release();

	//==================================
}

void MainGame::Update() // ����
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

void MainGame::Render(HDC hdc) // �׸��� ( ȭ�� ��� ) // �������۾��� ����ۿ� �����Ӵ����� 1/10�ʸ��� �ѹ��� ȭ�鿡 �ѷ���
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
		// ����۾��� ���� �ȿ��� �۾�.

		SCENEMANAGER->Render(backDC);


		//============================
		this->GetBackBuffer()->Render(hdc, 0, 0);
	}
}