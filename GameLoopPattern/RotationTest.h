#pragma once

class BattleShip;

class RotationTest : public GameNode
{
	BattleShip* pShip;

public:
	RotationTest();
	~RotationTest();

	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

