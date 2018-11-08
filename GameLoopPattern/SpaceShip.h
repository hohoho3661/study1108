#pragma once

class ProgressBar;

class SpaceShip
{
	RECT			rc;
	POINT			pt;
	
	float			speed;

	float			curHP;
	float			maxHP;


	Image*			image;
	ProgressBar*	hpBar;

public:
	SpaceShip();
	~SpaceShip();

	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);

};

