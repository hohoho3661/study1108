#include "stdafx.h"
#include "Enemy.h"
#include "Animation.h"

Enemy::Enemy()
{
}

Enemy::~Enemy()
{
}

bool Enemy::Init()
{
	// �̹��� ����
	_enemy = IMAGEMANAGER->findImage(TEXT("UFO"));
	assert(_enemy != NULL);
	
	vector<string> vPos;							// ���͸� �����
	vPos = TXTDATA->txtLoad(TEXT("EnemyData.txt")); // ���� ���Ϳ� ,,, ���Ͽ��� �ҷ��� ���Ͱ��� �Ѱ���
	

	//// ������ ����
	//_pt.x = WINSIZEX / 2;
	//_pt.y = 100;
	
	_pt.x = atoi(vPos[0].c_str()); // ?????????? ���Ͱ��� ��Ʈ�� ���� �迭�� �ٲ۰ǰ� ?
	_pt.y = atoi(vPos[1].c_str());

	// ��Ʈ �����
	_rc = RectMakeCenter(_pt.x, _pt.y, _enemy->GetFrameWidth(), _enemy->GetFrameHeight());

	// �ִϸ��̼�
	_ani = new Animation;
	_ani->Init(_enemy);
	_ani->setDefPlayFrame(false, true);
	_ani->setFPS(1); // ������ 1 �����Ӵ� (n) - ������Ʈ�� Ŀ������ ���� �ֱⰡ ª����.
	_ani->start(); // ���� �κп� ����.

	speed = 5;
	dir = 1;

	return true;
}

void Enemy::Release()
{
}

void Enemy::Update()
{
	if (_pt.x >= WINSIZEX || _pt.x <= 0)
	{
		dir *= -1;
	}

	_pt.x += speed * dir;
	_rc = RectMakeCenter(_pt.x, _pt.y, _enemy->GetFrameWidth(), _enemy->GetFrameHeight());
	
	_ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
}

void Enemy::Render(HDC hdc)
{
	
	//Rectangle(hdc, _rc.left, _rc.top, _rc.right, _rc.bottom);

	//_enemy->AniRender(hdc, _pt.x, _pt.y, _ani);
	_enemy->AniRender(hdc, _rc.left, _rc.top, _ani);

}
