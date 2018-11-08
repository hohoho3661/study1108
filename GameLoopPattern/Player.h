#pragma once

class Image;

class Player
{
	Image*	_siva;
	Animation*	_sivaAni;
	

	int		_nCount;
	int		_iIndex;


	POINT*	_pPos;

public:		
	Player();
	virtual ~Player();	

	virtual void Update();
	virtual void Render(HDC hdc);

	//========== Ä«¸Þ¶ó ==============
		
	void SetPos(POINT* p) { _pPos = p; }
	POINT* GetPos() { return _pPos; }
};

