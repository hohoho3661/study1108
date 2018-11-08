#pragma once

class MapTool : public GameNode
{
private:
	POINT		currentTile;

	Tile		sampleTile[SAMPLETILEX * SAMPLETILEY];
	Tile		tile[TILEX * TILEY];

	int			pos[2];
public:
	MapTool();
	~MapTool();

	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void MapToolSetup();

	void ClickSample();
	void ClickMap();

	void SaveTile();
	void LoadTile();
};

// 사용한다면, 수정해서 써야됨.
// 이 상태로는 오브젝트를 타일위에 올려놓기가 힘듬.
// 충돌처리 힘듬,
// 쿼터뷰보다 정방형타입을 추천.
// 