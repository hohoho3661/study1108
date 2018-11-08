#pragma once

class TankMap;
class Tank;

class TankMoveTest : public GameNode
{
private:
	TankMap*	tankMap;
	Tank*		tank;

public:
	TankMoveTest();
	~TankMoveTest();

	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

