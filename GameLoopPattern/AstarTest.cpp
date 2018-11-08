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
	// Ÿ���� �����ϰ� total list�� �ִ��۾�
	startTile = new tile;
	startTile->Init(4, 12); // ������ġ
	startTile->SetAttribute(TEXT("Start"));

	endTile = new tile;
	endTile->Init(30, 12); // ����ġ
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

	for (int i = 0; i < AddOpenList(currentTile).size(); ++i) // ���¸���Ʈ�� �ִ� ����ŭ �ݺ����� ���� f���� �� �������� ����. ���ȣ���
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

		// F���� ���� �������� ã�Ƽ�
		if (tempTotalCost > vOpenList[i]->GetTotalCost())
		{
			tempTotalCost = vOpenList[i]->GetTotalCost();
			tempTile = vOpenList[i];
		}

		bool addObj = true;


// ����ġ ������ ��������
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

	// End�� ã��
	if (tempTile->GetAttribute() == TEXT("End"))
	{
		while (currentTile->GetParentNode() != NULL)
		{
			currentTile->SetColor(RGB(22, 14, 128));
			currentTile = currentTile->GetParentNode();
		}
		return;
	}

	// Close�� �ְ�
	vCloseList.push_back(tempTile);

	// Open���� ����
	for (vOpenList_it = vOpenList.begin(); vOpenList_it != vOpenList.end(); ++vOpenList_it)
	{
		if (*vOpenList_it == tempTile)
		{
			vOpenList_it = vOpenList.erase(vOpenList_it);
			break;
		}
	}

	currentTile = tempTile;

	PathFinder(currentTile); // �������� ã�������� ����Լ�,, ------ ����Լ��ϱ� ( ��ûũ��, �Լ��� �ȴ����� ���ÿ� ��� �׿���, ������ ������ ������ )
}


// �̰� ������
// ���Ƿ� ���۰� ���� �����Ҽ��ְ� �ؾߵ�.
//
//