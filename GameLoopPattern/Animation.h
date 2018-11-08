#pragma once

class Image;

class Animation
{
public:
	typedef std::vector<POINT>		vFrameList;
	typedef std::vector<int>		vPlayList;

private:
	vFrameList						_frameList;
	vPlayList						_playList;

	int _frameNum;
	int _frameWidth;
	int _frameHeight;

	bool _loop;
	bool _play;

	float _frameUpdateSec;
	float _elapsedSec;

	DWORD _nowPlayIndex;

public:
	Animation();
	virtual ~Animation();

	bool Init(int totlaW, int totalH, int frameW, int frameH);
	bool Init(Image* image);

	void Release();

	void setDefPlayFrame(bool reverse = false, bool loop = false);    // ������, ����     ������� ó������ ������
	void setPlayFrame(int *playArr, int arLen, bool loop = false);		//				 Ư���迭�� �����Ӽ����� �־���� �� ������� �÷���
	void setPlayFrame(int start, int end, bool reverse = false, bool loop = false); //	 �������̱������� ó������ �������� �ƴѰ��. ���۰� ���� �������ְ� ���

	void setFPS(int framePerSec);

	void frameUpdate(float elapsedTime);

	void start();
	void stop();
	void pause();
	void resume();

	inline bool isPlay() { return _play; }
	inline POINT getFramePos() { return _frameList[_playList[_nowPlayIndex]]; }
	inline int getFrameWidth() { return _frameWidth; }
	inline int getFrameHeight() { return _frameHeight; }
};

