#include "stdafx.h"
#include "LoadingScene.h"
#include "ProgressBar.h"


LoadingScene::LoadingScene()
	: _bg(NULL), _loadingBar(NULL), _curCount(0)
{
}


LoadingScene::~LoadingScene()
{
}

bool LoadingScene::Init()
{
	_bg = IMAGEMANAGER->AddImage(TEXT("LoadingBG"), TEXT("Image/fire.bmp"),
		WINSIZEX, WINSIZEY, true, COLOR_M);
	assert(_bg != NULL);



	IMAGEMANAGER->AddImage(TEXT("FrontLoading"), TEXT("Image/hpBarTop.bmp"), 0, WINSIZEY - 20,
		WINSIZEX, 20, true, COLOR_M);
	IMAGEMANAGER->AddImage(TEXT("BackLoading"), TEXT("Image/hpBarBottom.bmp"), 0 , WINSIZEY - 20,
		WINSIZEX, 20, true, COLOR_M);

	_loadingBar = new ProgressBar;
	_loadingBar->Init(TEXT("FrontLoading"), TEXT("BackLoading"), 0, WINSIZEY - 20, WINSIZEX, 20);
	_loadingBar->SetGauge(0, 0);

	// ??   실행파일을 실행시켯을떄 os가 프로세스를 하나 만들고 ,, 해당 프로세스는 os에게 메모리를 할당받음

	//		프로세스	: 하나의 실행파일이 실행되는 단위
	//		쓰레드	: 처리 단위

	//		메인함수가 만들어질때, 메인쓰레드가 만들어짐 .. return 0하면 없어짐.
	//		그외 로직이 실행될수있는 프로세스단위 쓰레드를 임의로 만들수있다.

	//		쓰레드가 교차되면서 실행되는걸 contected swiching ??

	//		모든 쓰레드는 독자적인 스택을 가짐. ..  무한히 만들수는 없다.
	
	//	
	//_beginThreadEx
	

	CreateThread(
		NULL,			// SECURITY ATTRIBUTE 보안코드 (윈도우 시스템함수는 거의 이런게 있슴)
		0,				// 쓰레드가 사용할 스택 사이즈,,,  이 매개 변수가 0이면 새 스레드는 실행 파일의 기본 크기를 사용.
		ThreadFunction, // 쓰레드 콜백함수
		this,			// 콜백함수가 넘겨받을 매게변수,  ,,, 여기서는 LoadingScene* loadHelper = (LoadingScene*)lpParam;
		NULL,			// 플래그 ,, 생성과 동작을 나눠야 될떄 설정.
		0				// 쓰레드 아이디
	);


	return true;
}

void LoadingScene::Release()
{
	SAFE_DELETE(_loadingBar);
}

void LoadingScene::Update()
{
	_loadingBar->Update();
	_loadingBar->SetGauge(_curCount, 100);

	if (_curCount == 100)
	{
		SCENEMANAGER->ChangeScene(TEXT("InGame"));
	}
}

void LoadingScene::Render(HDC hdc)
{
	_bg->Render(hdc);
	_loadingBar->Render(hdc);
}

DWORD CALLBACK ThreadFunction(LPVOID lpParam) // 콜백.. 형태를 지켜줘야되는 함수,
{
	LoadingScene* loadHelper = (LoadingScene*)lpParam; // 자기자신을 쓰레드의 매게변수로 넘긴것.

	while (loadHelper->_curCount < 100) // 1부터 100까지 세고, 다 세면 넘김. ,,, 이부분에 파일을 로드하는 작업을 넣으면됨. 물론 지금단계에서는 순식간에 끝남.
	{
		for (int i = 0; i < 10000; ++i)
		{
			printf_s("로딩중\n");
		}
		loadHelper->_curCount++;
	}
	return 0;	// 쓰레드 종료. delete작업까지 됨.
}
