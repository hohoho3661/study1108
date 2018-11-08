#pragma once

#define TILEWIDTH	TILESIZE
#define TILEHEIGHT	TILESIZE

#define TILENUMX	(WINSIZEX/TILEWIDTH)
#define TILENUMY	(WINSIZEY/TILEHEIGHT)


class tile;

class AstarTest
{
public:
	typedef vector<tile*>					vTile;
	typedef vector<tile*>::iterator			vTile_it;

private:
	vTile vTotalList;
	vTile vOpenList;
	vTile vCloseList;

	vTile_it vTotalList_it;
	vTile_it vOpenList_it;
	vTile_it vCloseList_it;

	tile*	startTile;
	tile*	endTile;
	tile*	currentTile;

	int		count;
	bool	start;

public:
	AstarTest();
	~AstarTest();

	bool	Init();
	void	Release();
	void	Update();
	void	Render(HDC hdc);

	bool	SetTile();

	vTile	AddOpenList(tile* _currentTile);

	void	PathFinder(tile* _currentTile);
};

