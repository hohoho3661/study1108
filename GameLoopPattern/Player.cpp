#include "stdafx.h"
#include "Player.h"



Player::Player()
{	


	//ANIMANAGER->Init();
	ANIMANAGER->AddCoordAni(TEXT("RightRun"), TEXT("Player1"), 2, 7, 10, true);
	ANIMANAGER->AddCoordAni(TEXT("LeftRun1"), TEXT("Player1"), 8, 13, 10, true);

	_siva = IMAGEMANAGER->findImage(TEXT("Player1"));
	assert(_siva != NULL);

	_sivaAni = ANIMANAGER->FindAni(TEXT("LeftRun1"));

	_pPos = new POINT;
	_pPos->x = WINSIZEX/2;
	_pPos->y = WINSIZEY-100;

}


Player::~Player()
{
}

void Player::Update()
{
	// ¿ÞÂÊ
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_sivaAni = ANIMANAGER->FindAni(TEXT("LeftRun1"));
		ANIMANAGER->Start(TEXT("LeftRun1"));
		_pPos->x -= SIVASPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_pPos->x -= SIVASPEED;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_sivaAni = ANIMANAGER->FindAni(TEXT("LeftRun1"));
		ANIMANAGER->Stop(TEXT("LeftRun1"));
		_pPos->x -= SIVASPEED;
	}
	//


	// ¿À¸¥ÂÊ
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_sivaAni = ANIMANAGER->FindAni(TEXT("RightRun"));
		ANIMANAGER->Start(TEXT("RightRun"));
		_pPos->x += SIVASPEED;
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_pPos->x += SIVASPEED;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_sivaAni = ANIMANAGER->FindAni(TEXT("RightRun"));
		ANIMANAGER->Stop(TEXT("RightRun"));
		_pPos->x += SIVASPEED;
	}
	//



	ANIMANAGER->Update();
}

void Player::Render(HDC hdc)
{
	/*_siva->FrameRender(hdc,
		_pPos->x,
		_pPos->y,
		_siva->GetFrameX(), _siva->GetFrameY());*/
		
	_siva->AniRender(hdc, _pPos->x, _pPos->y, _sivaAni);

}
