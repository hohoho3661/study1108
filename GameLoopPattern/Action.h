#pragma once
class Action
{
	Image* image;

	float startX, startY;
	float endX, endY;

	float angle;

	float travelRange;
	float worldTimeCount;
	float time;

	bool isMoving;
	
public:
	Action();
	~Action();

	bool Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void MoveTo(Image* _image, float _endX, float _endY, float _time);  // 어디로 보낼것인지에 대한 세팅 함수
	void Moving();														// 세팅한 정보를 가지고 이동할 함수

	bool GetIsMoving() { return isMoving; }

};

