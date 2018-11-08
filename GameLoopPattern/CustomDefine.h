#pragma once

// 사용자 정의 자료형
enum TERRAIN
{
	TR_CEMENT, TR_GROUND, TR_GRASS, TR_WATER, TR_END,
};

//
struct Tile
{
	TERRAIN terrain;
	RECT	rc;
	int		frameX;
	int		frameY;
};

//enum DS_STATE
//{
//	LEFT = -1,
//	NONE,
//	RIGHT = 1
//};



//Extern
extern HWND			_hWnd;
extern HINSTANCE	_hInst;
extern POINT		_ptMouse;

extern HWND			_hWndAvi;
#if defined(_MOVIE_TEST)
#endif//



struct SPERE
{
	float x, y;
	float r;
};