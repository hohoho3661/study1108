#pragma once

class SpaceShip;
class Enemy;

class InGameScene : public GameNode
{
	SpaceShip*	ship;
	Enemy*		enemy;

public:
	InGameScene();
	~InGameScene();

	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};