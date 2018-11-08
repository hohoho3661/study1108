#pragma once

class AstarTest;

class AstarPathFindTest : public GameNode
{
	AstarTest* pTest;

public:
	AstarPathFindTest();
	~AstarPathFindTest();

	bool	Init();
	void	Release();
	void	Update();
	void	Render(HDC hdc);
};

