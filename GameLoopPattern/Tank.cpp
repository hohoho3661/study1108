#include "stdafx.h"
#include "Tank.h"
#include "TankMap.h"



Tank::Tank()
{
	image = IMAGEMANAGER->AddFrameImage(TEXT("Tank"),
		TEXT("Image/Tank.bmp"), 256, 128, 8, 4, true, COLOR_M);

	pos.x = TILESIZE;
	pos.y = TILESIZE;


	speed = 5;

	tankRC = RectMake(pos.x, pos.y, image->GetFrameWidth(), image->GetFrameHeight());
	
	posEnd.x = pos.x + image->GetFrameWidth();
	posEnd.y = pos.y + image->GetFrameHeight();
}


Tank::~Tank()
{
}

void Tank::Update()
{
	//Move();
	MoveEx();
	tankRC = RectMake(pos.x, pos.y, image->GetFrameWidth(), image->GetFrameHeight());

}

void Tank::Render(HDC hdc)
{
	image->FrameRender(hdc, pos.x, pos.y, image->GetFrameX(), image->GetFrameY());
	Rectangle(hdc, tankRC.left, tankRC.top, tankRC.right, tankRC.bottom);
}

void Tank::Move()
{
	POINT	dirPos = pos;

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		dirPos.y -= speed;
		if (!IsWater(GetTilePos(dirPos)))
		{
			pos.y -= speed;
		}
		image->SetFrameY(0);
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		dirPos.y += image->GetFrameHeight();
		if (!IsWater(GetTilePos(dirPos)))
		{
			pos.y += speed;
		}
		image->SetFrameY(1);
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		dirPos.x += image->GetFrameWidth();
		if (!IsWater(GetTilePos(dirPos)))
		{
			pos.x += speed;
		}
		image->SetFrameY(2);
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		dirPos.x -= speed;
		if (!IsWater(GetTilePos(dirPos)))
		{
			pos.x -= speed;
		}
		image->SetFrameY(3);
	}
	
	////// 칸으로 움직이기
	//POINT	dirPos = pos;

	//if (KEYMANAGER->isOnceKeyDown(VK_UP))
	//{
	//	dirPos.y -= TILESIZE;
	//	if (!IsWater(GetTilePos(dirPos)))
	//	{
	//		pos.y -= TILESIZE;
	//	}
	//	image->SetFrameY(0);
	//}
	//if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	//{
	//	dirPos.y += image->GetFrameHeight();
	//	if (!IsWater(GetTilePos(dirPos)))
	//	{
	//		pos.y += TILESIZE;
	//	}
	//	image->SetFrameY(1);
	//}
	//if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	//{
	//	dirPos.x += image->GetFrameWidth();
	//	if (!IsWater(GetTilePos(dirPos)))
	//	{
	//		pos.x += TILESIZE;
	//	}
	//	image->SetFrameY(2);
	//}
	//if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	//{
	//	dirPos.x -= TILESIZE;
	//	if (!IsWater(GetTilePos(dirPos)))
	//	{
	//		pos.x -= TILESIZE;
	//	}
	//	image->SetFrameY(3);
	//}
}

void Tank::MoveEx()
{
	POINT	dirPos = pos;
	POINT	dirPosEnd = posEnd;

	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		dirPos.y -= speed;
		dirPosEnd.y -= speed;

		if (!IsWater(GetTilePos(dirPos)))
		{
			if (!IsWater(GetTilePos(dirPosEnd)))
			{
				pos.y -= speed;
				posEnd.y -= speed;
			}
		}
		image->SetFrameY(0);
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		dirPos.y += image->GetFrameHeight();
		dirPosEnd.y += image->GetFrameHeight();

		if (!IsWater(GetTilePos(dirPos)))
		{
			if (!IsWater(GetTilePos(dirPosEnd)))
			{
				pos.y += speed;
				posEnd.y += speed;

			}
				image->SetFrameY(1);			
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		dirPos.x += image->GetFrameWidth();
		dirPosEnd.x += image->GetFrameWidth();

		if (!IsWater(GetTilePos(dirPos)))
		{
			if (!IsWater(GetTilePos(dirPosEnd)))
			{
				pos.x += speed;
				posEnd.x += speed;

			}
		}
		image->SetFrameY(2);
	}

	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		dirPos.x -= speed;
		dirPosEnd.x -= speed;

		if (!IsWater(GetTilePos(dirPos)))
		{
			if (!IsWater(GetTilePos(dirPosEnd)))
			{
				pos.x -= speed;
				posEnd.x -= speed;

			}
		}
		image->SetFrameY(3);
	}
}

POINT Tank::GetTilePos(POINT pos)
{
	POINT	tilePos = {};
	Tile*	tile;
	tile = tankMap->GetTile();

	for (int i = 0; i < TILEX* TILEY; i++)
	{
		if (PtInRect(&(tile[i].rc), pos))
		{
			tilePos.x = tile[i].frameX;
			tilePos.y = tile[i].frameY;
		}
	}

	return tilePos;
}

bool Tank::IsWater(POINT pos)
{
	if (pos.x == 4 && pos.y == 0)
		return true;
	else if (pos.x == 0 && pos.y == 3)
		return true;

	return false;
}
