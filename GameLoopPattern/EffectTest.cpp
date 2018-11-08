#include "stdafx.h"
#include "EffectTest.h"



EffectTest::EffectTest()
{
}


EffectTest::~EffectTest()
{
}

bool EffectTest::Init()
{
	EFFECTMANAGER->AddEffect(TEXT("Effect1"), TEXT("Image/effect5.bmp"),
		740, 444, 148, 148, 1, 1.0f, 10);
	EFFECTMANAGER->AddEffect(TEXT("Effect2"), TEXT("Image/explosion.bmp"),
		832, 62, 32, 62, 1, 1.0f, 10); // 맨뒤 인자가 이펙트의 갯수.
	// 이미지가 출력이되는 객체를 만듬.
	// 

	// 사운드
	SOUNDMANAGER->Init();
	SOUNDMANAGER->AddSound(TEXT("Sound1"), TEXT("Sound/effect.wav"), false, false);
	SOUNDMANAGER->AddSound(TEXT("Sound2"), TEXT("Sound/effect2.wav"), false, false);

	// 배경음악은 인잇에서 Play시키자.

	return true;
}

void EffectTest::Release()
{
}

void EffectTest::Update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		GetCursorPos(&_ptMouse);
		ScreenToClient(_hWnd, &_ptMouse);
		EFFECTMANAGER->Play(TEXT("Effect1"), _ptMouse);
		SOUNDMANAGER->Play(TEXT("Sound1"), 0.5);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		GetCursorPos(&_ptMouse);
		ScreenToClient(_hWnd, &_ptMouse);
		EFFECTMANAGER->Play(TEXT("Effect2"), _ptMouse);
		SOUNDMANAGER->Play(TEXT("Sound2"), 0.5);
	}

	EFFECTMANAGER->Update();
	//SOUNDMANAGER->Update();
}

void EffectTest::Render(HDC hdc)
{
	EFFECTMANAGER->Render(hdc);
}
