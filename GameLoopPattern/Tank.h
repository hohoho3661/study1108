#pragma once

class TankMap;

class Tank
{
private:
	TankMap*		tankMap;
	Image*			image;
	POINT			pos;
	int				speed;

	//
	RECT			tankRC;
	POINT			posEnd;

public:
	Tank();
	~Tank();

	void			Update();
	void			Render(HDC hdc);

	void			Move();
	void			MoveEx();

	POINT			GetTilePos(POINT pos);
	//				GetTilePos();

	bool			IsWater(POINT pos);

	inline void		SetTankMap(TankMap* map) { tankMap = map; }
};

