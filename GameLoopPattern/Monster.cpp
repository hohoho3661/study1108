#include "stdafx.h"
#include "Monster.h"



Monster::Monster()
{
	//_monster = new Image;
	//_monster->Init(TEXT("SpriteImage/Monster.bmp"), 358, 632, 2, 4, true, RGB(255, 0, 255)); // �����̸�... �̹�����ü x,yũ�� ... ���̹����� ���� x��, y��.

	_monster = IMAGEMANAGER->findImage("Monster");
	assert(_monster != NULL);

	_monster->SetX(WINSIZEX - 200);
	_monster->SetY(WINSIZEY - 200);

	_Golem = RectMake(WINSIZEX-200,WINSIZEY-200, 358/2, 632/4);

	_dir = 1;
	//_dir = 0; // �ϴ� �������.. �׽�Ʈ��
}


Monster::~Monster()
{
	SAFE_DELETE(_monster);
}

void Monster::Update()
{
	//switch (_dir)
	//{
	//case 1:										// _dir�� �ʱⰪ�� 1�̴ϱ� X�������� --;
	//	{
	//		_monster->SetX(_monster->GetX() - 3);
	//		_dirChange = true;
	//		_monster->SetFrameX(0);
	//		OffsetRect(&_Golem, -3, 0);
	//	}
	//	break;
	//case -1:
	//	{
	//		_monster->SetX(_monster->GetX() + 3);
	//		_dirChange = false;
	//		_monster->SetFrameX(1);
	//		OffsetRect(&_Golem, 3, 0);
	//	}
	//	break;
	//}
	//if (_Golem.right > WINSIZEX || _Golem.left <= 0) // ���ʳ��� �������.
	//	_dir *= -1;									 // ����ġ���� �� �Ű����� _dir�� �ٲ���.

	
	_nCount++;

	if (_nCount % 10 == 0) // 1/100�ʸ��� �ϳ��� �׷���. (������ 1/1000���ε�.. 10�� 1���ϱ�) ..... ������ skiping.
	{
		if (_dirChange)
		{
			if (_iIndex <= 0)
				_iIndex = 4;

			_iIndex--;

			_monster->SetFrameY(_iIndex);
		}
		else
		{
			if (_iIndex >= _monster->GetMaxFrameY())
				_iIndex = 0;

			_iIndex++;

			_monster->SetFrameY(_iIndex);
		}

		_nCount = 0;
	}
}

void Monster::Render(HDC hdc)
{
//	Rectangle(hdc, _Golem.left, _Golem.top, _Golem.right, _Golem.bottom);  // Ȯ�ο�! ���߿� �ּ�ó��!!!!!!!!!!!!

	_monster->FrameRender(hdc, _monster->GetX(), _monster->GetY(),
		_monster->GetFrameX(), _monster->GetFrameY());
}
