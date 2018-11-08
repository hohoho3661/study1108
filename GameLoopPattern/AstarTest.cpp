#include "stdafx.h"
#include "AstarTest.h"

#include "tile.h"

AstarTest::AstarTest()
{
}

AstarTest::~AstarTest()
{
}

bool AstarTest::Init()
{
	if (!SetTile())
		return false;

	count = 0;
	start = false;
	

	return true;
}

void AstarTest::Release()
{
}

void AstarTest::Update()
{
	if (KEYMANAGER->isOnceKeyDown('S'))
	{
		PathFinder(currentTile);
	}
	if (start)
	{
		count++;
		if (count % 5 == 0)
		{
			PathFinder(currentTile);
			count = 0;
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_LBUTTON))
	{
		GetCursorPos(&_ptMouse);
		ScreenToClient(_hWnd, &_ptMouse);

		for (int i = 0; i < vTotalList.size(); ++i)
		{
			if (PtInRect(&vTotalList[i]->GetRect(), _ptMouse))
			{
				if (vTotalList[i]->GetAttribute() == TEXT("Start"))
					continue;
				if (vTotalList[i]->GetAttribute() == TEXT("End"))
					continue;

				vTotalList[i]->SetIsOpen(false);
				vTotalList[i]->SetAttribute(TEXT("Wall"));
				vTotalList[i]->SetColor(RGB(230, 140, 200));
				break;
			}
		}
	}

}

void AstarTest::Render(HDC hdc)
{
	for (int i = 0; i < vTotalList.size(); ++i)
	{
		vTotalList[i]->Render(hdc);
	}
}

//================================================================================
//================================================================================
//================================================================================


bool AstarTest::SetTile()
{
	// 타일을 세팅하고 total list에 넣는작업
	startTile = new tile;
	startTile->Init(4, 12); // 시작위치
	startTile->SetAttribute(TEXT("Start"));

	endTile = new tile;
	endTile->Init(30, 12); // 끝위치
	endTile->SetAttribute(TEXT("End"));

	currentTile = startTile;

	for (int i = 0; i < TILENUMY; i++)
	{
		for (int j = 0; j < TILENUMX; ++j)
		{
			if (j == startTile->GetIdX() && i == startTile->GetIdY())
			{
				startTile->SetColor(RGB(0, 255, 255));
				vTotalList.push_back(startTile);
				continue;
			}

			if (j == endTile->GetIdX() && i == endTile->GetIdY())
			{
				endTile->SetColor(RGB(10, 155, 55));
				vTotalList.push_back(endTile);
				continue;
			}

			tile* node = new tile;
			node->Init(j, i);
			vTotalList.push_back(node);
		}
	}
	
	return true;
}

AstarTest::vTile AstarTest::AddOpenList(tile * _currentTile)
{
	int startX = currentTile->GetIdX() - 1;
	int startY = currentTile->GetIdY() - 1;

	//int startX = currentTile->GetIdX() > 0 ? currentTile->GetIdX() - 1 : 0;
	//int startY = currentTile->GetIdY() > 0 ? currentTile->GetIdY() - 1 : 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			tile* node = vTotalList[(startY * TILENUMX) + startX + j + (i*TILENUMX)];

			if (!node->GetIsOpen())
				continue;
			if (node->GetAttribute() == TEXT("Start"))
				continue;
			if (node->GetAttribute() == TEXT("Wall"))
				continue;

			node->SetParentNode(currentTile);

			bool addObj = true;

			for (vOpenList_it = vOpenList.begin(); vOpenList_it != vOpenList.end(); ++vOpenList_it)
			{
				if (*vOpenList_it == node)
				{
					addObj = false;
					break;
				}
			}

			if (node->GetAttribute() != TEXT("End"))
				node->SetColor(RGB(128, 64, 28));

			if (!addObj)
				continue;

			vOpenList.push_back(node);
		}
	}

	return vOpenList;
}

void AstarTest::PathFinder(tile * _currentTile)
{
	float tempTotalCost = 50000.f;

	tile* tempTile = NULL;

	for (int i = 0; i < AddOpenList(currentTile).size(); ++i) // 오픈리스트에 있는 수만큼 반복문을 돌며 f값이 젤 작은값을 구함. 재귀호출로
	{
		// H
		vOpenList[i]->SetCostToGoal(
			(abs(endTile->GetIdX() - vOpenList[i]->GetIdX()) +
				abs(endTile->GetIdY() - vOpenList[i]->GetIdY())) * 10);

		// G
		POINT center1 = vOpenList[i]->GetParentNode()->GetCenter();
		POINT center2 = vOpenList[i]->GetCenter();
		vOpenList[i]->SetCostFromStart((UTIL::getDistance(center1.x, center1.y, center2.x, center2.y) > TILEWIDTH) ? 14 : 10);
		// F
		vOpenList[i]->SetTotalCost(vOpenList[i]->GetCostToGoal() + vOpenList[i]->GetCostFromStart());

		// F값이 제일 작은것을 찾아서
		if (tempTotalCost > vOpenList[i]->GetTotalCost())
		{
			tempTotalCost = vOpenList[i]->GetTotalCost();
			tempTile = vOpenList[i];
		}

		bool addObj = true;


// 포이치 문으로 수정가능
		//for (vOpenList_it = vOpenList.begin(); vOpenList_it != vOpenList.end(); ++vOpenList_it)
		//{
		//	if (*vOpenList_it == tempTile)
		//	{
		//		addObj = false;
		//		break;
		//	}
		//}

//		
		for (auto a : vOpenList)
		{
			if (a == tempTile)
			{
				addObj = false;
				break;
			}
		}





		vOpenList[i]->SetIsOpen(false);

		if (!addObj)
			continue;

		vOpenList.push_back(tempTile);
	}

	// End를 찾고
	if (tempTile->GetAttribute() == TEXT("End"))
	{
		while (currentTile->GetParentNode() != NULL)
		{
			currentTile->SetColor(RGB(22, 14, 128));
			currentTile = currentTile->GetParentNode();
		}
		return;
	}

	// Close에 넣고
	vCloseList.push_back(tempTile);

	// Open에서 지움
	for (vOpenList_it = vOpenList.begin(); vOpenList_it != vOpenList.end(); ++vOpenList_it)
	{
		if (*vOpenList_it == tempTile)
		{
			vOpenList_it = vOpenList.erase(vOpenList_it);
			break;
		}
	}

	currentTile = tempTile;

	PathFinder(currentTile); // 목적지를 찾을때까지 재귀함수,, ------ 재귀함수니까 ( 엄청크면, 함수가 안닫히고 스택에 계속 쌓여서, 한정된 스택이 못버팀 )
}


// 이걸 쓰려면
// 임의로 시작과 끝을 지정할수있게 해야됨.
//
//