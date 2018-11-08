#pragma once

class ProgressBar;

// 로딩을 하는 씬
// 

// 장면단위로 만들고 삭제하는 관리를 쉽게하기위해 씬을 만듬.

class LoadingScene : public GameNode
{
	ProgressBar*		_loadingBar;
	Image*				_bg;



public:
	LoadingScene();
	~LoadingScene();
	
	int					_curCount;

	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};

static DWORD CALLBACK ThreadFunction(LPVOID lpParam);