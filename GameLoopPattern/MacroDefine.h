#pragma once

// 사용자 정의 빌드 구분

//#define _RENDER_TEST
//#define _CROP_TEST
//#define _FRAME_TEST
//#define _TRIFUNC_TEST
//#define _STALKER_TEST
//#define _ANI_TEST
//#define _CAMERA_TEST
//#define _PIXEL_TEST
//#define _EFFECT_TEST
//#define _ALPHA_TEST
//#define _MOVIE_TEST
#define _MAPTOOL_TEST


#define PI			3.141592
#define PI2			PI*2
#define COLOR_M		RGB(255,0,255)

// tile 관련 매크로
#define TILESIZE	32

#define TILEX		20
#define TILEY		20

#define TILESIZEX	TILESIZE * TILEX
#define TILESIZEY	TILESIZE * TILEY

#define SAMPLETILEX	20
#define SAMPLETILEY	9


// ============== 두가지 문자셋을 안전하게 디파인? ( 유니코드, 멀티바이팅 ) =======================
#if defined(_UNICODE)
	typedef std::wstring	tstring;	//std::basic_string<wchar>
#else
	typedef std::string		tstring;	//std::basic_string<char>
#endif // #if defined(_UNICODE)


// 시바런
#define SIVASPEED	5
#define SIVAPUSH	50


// 메모리 해제 매크로
// Backbuffer
#define SAFE_DELETE(p)	{if(p) {delete(p);(p) = NULL;}}
#define SAFE_RELEASE(p)	{if(p) {(p)->Release(); (p) = NULL;}}

// 윈도우 사이즈 관련 매크로
#define WINSTYLE	WS_CAPTION | WS_SYSMENU

#define WINSIZEX	1500
#define WINSIZEY	800
#define WINSTARTX	100
#define WINSTARTY	100

// 싱글턴 객체 매크로
#define RAND			RandomFunction::getSingleton()
#define CAMERA			Camera::getSingleton()

#define IMAGEMANAGER	ImageManager::getSingleton()
#define KEYMANAGER		KeyManager::getSingleton()
#define TIMEMANAGER		TimeManager::getSingleton()
#define EFFECTMANAGER	EffectManager::getSingleton()
#define SCENEMANAGER	SceneManager::getSingleton()
#define SOUNDMANAGER	SoundManager::getSingleton()
#define TXTDATA			TextData::getSingleton()
#define ANIMANAGER		AniManager::getSingleton()