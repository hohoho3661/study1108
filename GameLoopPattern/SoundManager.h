#pragma once
#include "SingleTon.h"


// FMOD�� ���� WAV ������ ��ߵ�.


#include "inc/fmod.hpp"							// FMOD ����� ���� ���̺귯�� ���,,, dll
#pragma comment(lib, "lib/fmodex_vc.lib")

using namespace FMOD;   // fmod�� ���¼ҽ��̱��ѵ�, �����߱� ���ӿ� ����ϸ� ���Ḧ ���ߵ�.

#define TOTALSOUNDBUFFER 15 // ���ÿ� ����Ҽ� �ִ� ���� ä�� �� ,, ���ϼ��� �޸𸮸� ���̸����ϱ� ,, ������ ���鶧 ������ ���� ������.

struct SoundInfo
{
	Sound*		sound;			// �ε��� ���� ����
	Channel*	channel;		// ������ ����
};

class SoundManager : public SingletonBase<SoundManager>
{
private:
	System * _system;

	map<string, SoundInfo*>				totalSound;		// �������� �����ϴ� ��
	map<string, SoundInfo*>::iterator	it;
public:
	SoundManager();
	~SoundManager();

	bool		Init();
	void		Release();
	void		Update();


	void		AddSound(string keyName, string soundName, bool bgm, bool loop);

	void		Play(string keyName, float volume);
	void		Stop(string keyName);
	void		Pause(string keyName);
	void		Resume(string keyName);

	bool		isPlaySound(string keyName);
	bool		isPauseSound(string keyName);

	bool		ErrCheck(FMOD_RESULT result);
};

