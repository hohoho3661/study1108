#pragma once
#include "GameNode.h"

struct Stalker
{
	float x, y;
	float angle;
	float endx, endy;
	float length;
	float speed;

	RECT rc;
};

class StalkerTest : GameNode
{
	Stalker _skr1;
	Stalker _skr2;


public:
	StalkerTest();
	virtual ~StalkerTest();

	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};

// ����
// 4���⿡�� �� ����.. ���� ������°ɷ�
//
// �浹ó��
// �÷��̾�� �Ѿ� �߻�, ���ʹ̴� �÷��̾�� �浹������ ....ó��
// 
// 