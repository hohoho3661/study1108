#pragma once
class AlphaRenderTest : public GameNode
{
private:
//	Enemy*		ufo;


public:
	AlphaRenderTest();
	~AlphaRenderTest();

	virtual bool Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};

