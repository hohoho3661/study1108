#pragma once

// ����������� �� ���� ������ ��.

class Button;

class StartScene : public GameNode
{
//	RECT	selectButton;
	Button*	pButton;

public:
	StartScene();
	~StartScene();

	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	static void cbSceneChange();
};