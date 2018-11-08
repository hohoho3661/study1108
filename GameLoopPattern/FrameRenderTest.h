#pragma once

class Player;
class Monster;

class FrameRenderTest : public GameNode
{
	Image*	_background;

	int		indexBlend;

	//Image*	_siva;
	//Image*	_monster;
	
	//RECT		clientRC;

	Player*		player;
	Monster*	monster;

public:
	FrameRenderTest();
	virtual ~FrameRenderTest();

	void CheckRect(); // 충돌처리.

	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};
