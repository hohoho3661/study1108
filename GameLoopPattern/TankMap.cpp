#include "stdafx.h"
#include "TankMap.h"

TankMap::TankMap()
{
}

TankMap::~TankMap()
{
}

bool TankMap::Load()
{
	HANDLE	file;
	DWORD	read;

	file = CreateFile(TEXT("mapData.map"), GENERIC_READ, NULL, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	//ReadFile(file, tile, sizeof(Tile)*TILEX*TILEY, &read, NULL);

	//CloseHandle(file);

	if (file == INVALID_HANDLE_VALUE)
		return false;

	if (!ReadFile(file, tile, sizeof(Tile)*TILEX*TILEY, &read, NULL))
		return false;

	CloseHandle(file);

	return true;
}

void TankMap::Render(HDC hdc)
{
	for (int i = 0; i < TILEX*TILEY; i++)
	{
		IMAGEMANAGER->FrameRender(TEXT("Tile"), hdc,
			tile[i].rc.left, tile[i].rc.top,
			tile[i].frameX, tile[i].frameY);
	}
}
