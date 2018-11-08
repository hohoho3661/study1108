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
	// 이미지 세팅
	_enemy = IMAGEMANAGER->findImage(TEXT("UFO"));
	assert(_enemy != NULL);
	
	vector<string> vPos;							// 백터를 만들고
	vPos = TXTDATA->txtLoad(TEXT("EnemyData.txt")); // 만든 백터에 ,,, 파일에서 불러온 백터값을 넘겨줌
	

	//// 포지션 세팅
	//_pt.x = WINSIZEX / 2;
	//_pt.y = 100;
	
	_pt.x = atoi(vPos[0].c_str()); // ?????????? 백터값에 스트링 값을 배열로 바꾼건가 ?
	_pt.y = atoi(vPos[1].c_str());

	// 렉트 만들기
	_rc = RectMakeCenter(_pt.x, _pt.y, _enemy->GetFrameWidth(), _enemy->GetFrameHeight());

	// 애니메이션
	_ani = new Animation;
	_ani->Init(_enemy);
	_ani->setDefPlayFrame(false, true);
	_ani->setFPS(1); // 프레임 1 프레임당 (n) - 업데이트가 커질수록 갱신 주기가 짧아짐.
	_ani->start(); // 인잇 부분에 넣자.

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
