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

	// ??   ���������� ����������� os�� ���μ����� �ϳ� ����� ,, �ش� ���μ����� os���� �޸𸮸� �Ҵ����

	//		���μ���	: �ϳ��� ���������� ����Ǵ� ����
	//		������	: ó�� ����

	//		�����Լ��� ���������, ���ξ����尡 ������� .. return 0�ϸ� ������.
	//		�׿� ������ ����ɼ��ִ� ���μ������� �����带 ���Ƿ� ������ִ�.

	//		�����尡 �����Ǹ鼭 ����Ǵ°� contected swiching ??

	//		��� ������� �������� ������ ����. ..  ������ ������� ����.
	
	//	
	//_beginThreadEx
	

	CreateThread(
		NULL,			// SECURITY ATTRIBUTE �����ڵ� (������ �ý����Լ��� ���� �̷��� �ֽ�)
		0,				// �����尡 ����� ���� ������,,,  �� �Ű� ������ 0�̸� �� ������� ���� ������ �⺻ ũ�⸦ ���.
		ThreadFunction, // ������ �ݹ��Լ�
		this,			// �ݹ��Լ��� �Ѱܹ��� �ŰԺ���,  ,,, ���⼭�� LoadingScene* loadHelper = (LoadingScene*)lpParam;
		NULL,			// �÷��� ,, ������ ������ ������ �ɋ� ����.
		0				// ������ ���̵�
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

DWORD CALLBACK ThreadFunction(LPVOID lpParam) // �ݹ�.. ���¸� ������ߵǴ� �Լ�,
{
	LoadingScene* loadHelper = (LoadingScene*)lpParam; // �ڱ��ڽ��� �������� �ŰԺ����� �ѱ��.

	while (loadHelper->_curCount < 100) // 1���� 100���� ����, �� ���� �ѱ�. ,,, �̺κп� ������ �ε��ϴ� �۾��� �������. ���� ���ݴܰ迡���� ���İ��� ����.
	{
		for (int i = 0; i < 10000; ++i)
		{
			printf_s("�ε���\n");
		}
		loadHelper->_curCount++;
	}
	return 0;	// ������ ����. delete�۾����� ��.
}
