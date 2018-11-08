#pragma once

enum BUTTONDIR
{
	BUTTONDIR_NONE,
	BUTTONDIR_UP,
	BUTTONDIR_DOWN,
};

typedef void(*FUNC)();


class Button
{
	BUTTONDIR		_direction;

	string			_imageName;
	Image*			_image;
	RECT			_rc;
	float			_x, _y;
	POINT			_btnDownFramePoint;
	POINT			_btnUpFramePoint;

	FUNC			_callBackFunc;

public:
	Button();
	~Button();

	bool Init(const string imageName, int x, int y, POINT btnDownFramePoint, POINT btnUpFramePoint, FUNC pFunc);

	void Release();
	void Update();
	void Render(HDC hdc);

};

// �ݹ��Լ��� ���� �ŰԺ����� �Լ�������,,,

// �Լ� ������
// �Լ� �̸����� ã�°Ծƴ϶�, �Լ��� ����Ǵ� ��ġ�� ���� ȣ��.

// ��ȯ��(*�Լ���)(�Ű����� ����Ʈ);
// typedef void(*Func)(int);  // ��ȣ�� �߿伺!
// 							   ex) typedef void* Func (int); ----> ��ȣ�� ������ ���̵� �����͸� ��ȯ�������ϴ� �Ϲ��Լ��� �Ǿ����

// Func pFunc		=	Function; // �Լ��̸��� �������ִ½����� �� �Լ��� �����ִ�.
// �Լ��������� ����	=	�Լ��� (��ȣ�� ���� �Լ���)
// ����Ǿ��ִ� �Լ����������� ���� ( ��ȯ��, �ŰԺ��� �ڷ��� )�� ���� ��ġ�ؾ� �ȴ�. ***************


// ����� �Լ������ʹ� �Լ� ���·� ��� ����.
// (*Func)(10); => pFunc(10); ���ڿ� ���� ȣ�⵵ ������ش�.


// �Լ��������� ������ ĳ������ ���� (�߾Ⱦ�)
// int(*Func1)(int), float(*Func2)(float);
// Func1 = (int(*)(int))Func2;

// 

// Ŭ���� ������ ����ϴ� �Լ��� ������ �������� ���ѵ�.
// ��ü�� �����ؾߵǴµ�,,, �׷��� ���������� ����ϱⰡ ����.

//
//

// �ᱹ�� �ʿ��Ѱ����� ����ƽ������ �ʼ���
// �ٶ����� �ڵ��� �ƴϴ�.



// C++������ �Լ�������
// std::function<void(*)()> pFunc;



//
//// �Լ� ��ü
//class AAA
//{
//public:
//	bool operator()(int n)
//	{
//		return 10 < n;
//	}
//};
//
//AAA a;
//bool n = a(1);
////
//



//int Func1(int n)		// �Լ��� �����
//{
//	return (n + 10);
//}
//
//std::function<int(int)> pFunc = Func1;	// �Լ��� ��üó�� �ѱ��
//
//int n = pFunc(10);				// �����ؼ� ��밡��.