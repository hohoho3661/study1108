#pragma once

class tile
{
private:
	int			idX; // 타일의 인덱스
	int			idY; //

	POINT		center;

	RECT		rc;

	float		totalCost;		// F
	float		costFromStart;	// G
	float		costToGoal;		// H

	bool		isOpen;			// Open 여부

	tile*		parentNode;		// 부모 노드

	// 그리는데 필요한 요소
	COLORREF	color;
	HBRUSH		brush;
	HPEN		pen;

	string		attiribute;

public:
	tile();
	~tile();

	bool		Init(int _idX, int _idY);
	void		Release();
	void		Update();
	void		Render(HDC hdc);
	

	// private 맴버에 접근하기위한 접근 지정자
	int			GetIdX() { return idX; }
	int			GetIdY() { return idY; }

	void		SetColor(COLORREF _color);

	RECT		GetRect() { return rc; }

	void		SetCenter(POINT _center) { center = _center; }
	POINT		GetCenter() { return center; }

	void		SetAttribute(string str) { attiribute = str; }
	string		GetAttribute() { return attiribute; }

	void		SetTotalCost(float _totalcost) { totalCost = _totalcost; }
	float		GetTotalCost() { return totalCost; }

	void		SetCostFromStart(float _costFromStart) { costFromStart = _costFromStart; }
	float		GetCostFromStart() { return costFromStart; }

	void		SetCostToGoal(float _costToGoal) { costToGoal = _costToGoal; }
	float		GetCostToGoal() { return costToGoal; }

	void		SetParentNode(tile* t) { parentNode = t; }
	tile*		GetParentNode() { return parentNode; }

	void		SetIsOpen(bool _isOpen) { isOpen = _isOpen; }
	bool		GetIsOpen() { return isOpen; }

};

//길찾기 알고리즘
//
// A*
//
//단점 : 다 체크하고나서야 이동할수 없다는 결과를 줌
//	 (시작지점에서는 장애물이있는지 없는지 알수가 없슴)
//
//	- 맵이 바뀔때
//
//	- 시작지점을 기준으로
//	다음으로 이동할때 최소비용을 찾는것
//
//	F = G + H
//
//	시작 - 도착
//	목적지 - 시작
//
//	g = 시작지점에서 다음으로 갈때 소요되는 비용
//
//	h = 현재위치에서 목적지 까지의 비용
//	(가중치 ? )
//
//	f = 합친비용
//
//	====================================
//	1. openlist에 8방향값 넣고
//
//	2. f값 계산
//
//	3. closelist에 가장 낮은 f값(비용) 집어넣고
//
//	4. 타일속성에 시작, 도착, 장애물 타입 부여
//
//	5. 도착지점에서 거꾸로 찾기
//	====================================
//
//
//	==========================
// 다익스트라
//
//	- 맵이 안바뀔때
//
//	- 검색대상에대한 모든루트에대한 결과를 보고
//	시작과 끝이 정해지면 계산된 루트를 통해
//	최단거리를 찾는거