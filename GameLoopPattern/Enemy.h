#pragma once



class Enemy
{
private:
	Image *		_enemy;
	Animation*	_ani;

	RECT		_rc;
	POINT		_pt;

	int			speed;
	int			dir;

public:
	Enemy();
	~Enemy();

	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};

