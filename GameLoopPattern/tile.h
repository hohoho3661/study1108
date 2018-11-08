#pragma once

class tile
{
private:
	int			idX; // Ÿ���� �ε���
	int			idY; //

	POINT		center;

	RECT		rc;

	float		totalCost;		// F
	float		costFromStart;	// G
	float		costToGoal;		// H

	bool		isOpen;			// Open ����

	tile*		parentNode;		// �θ� ���

	// �׸��µ� �ʿ��� ���
	COLORREF	color;
	HBRUSH		brush;
	HPEN		pen;

	string		attiribute;

public:
	tile();
	~tile();

	bool		Init(int _idX, int _idY);
	void		Release();
	void		Update();
	void		Render(HDC hdc);
	

	// private �ɹ��� �����ϱ����� ���� ������
	int			GetIdX() { return idX; }
	int			GetIdY() { return idY; }

	void		SetColor(COLORREF _color);

	RECT		GetRect() { return rc; }

	void		SetCenter(POINT _center) { center = _center; }
	POINT		GetCenter() { return center; }

	void		SetAttribute(string str) { attiribute = str; }
	string		GetAttribute() { return attiribute; }

	void		SetTotalCost(float _totalcost) { totalCost = _totalcost; }
	float		GetTotalCost() { return totalCost; }

	void		SetCostFromStart(float _costFromStart) { costFromStart = _costFromStart; }
	float		GetCostFromStart() { return costFromStart; }

	void		SetCostToGoal(float _costToGoal) { costToGoal = _costToGoal; }
	float		GetCostToGoal() { return costToGoal; }

	void		SetParentNode(tile* t) { parentNode = t; }
	tile*		GetParentNode() { return parentNode; }

	void		SetIsOpen(bool _isOpen) { isOpen = _isOpen; }
	bool		GetIsOpen() { return isOpen; }

};

//��ã�� �˰���
//
// A*
//
//���� : �� üũ�ϰ����� �̵��Ҽ� ���ٴ� ����� ��
//	 (�������������� ��ֹ����ִ��� ������ �˼��� ����)
//
//	- ���� �ٲ�
//
//	- ���������� ��������
//	�������� �̵��Ҷ� �ּҺ���� ã�°�
//
//	F = G + H
//
//	���� - ����
//	������ - ����
//
//	g = ������������ �������� ���� �ҿ�Ǵ� ���
//
//	h = ������ġ���� ������ ������ ���
//	(����ġ ? )
//
//	f = ��ģ���
//
//	====================================
//	1. openlist�� 8���Ⱚ �ְ�
//
//	2. f�� ���
//
//	3. closelist�� ���� ���� f��(���) ����ְ�
//
//	4. Ÿ�ϼӼ��� ����, ����, ��ֹ� Ÿ�� �ο�
//
//	5. ������������ �Ųٷ� ã��
//	====================================
//
//
//	==========================
// ���ͽ�Ʈ��
//
//	- ���� �ȹٲ�
//
//	- �˻���󿡴��� ����Ʈ������ ����� ����
//	���۰� ���� �������� ���� ��Ʈ�� ����
//	�ִܰŸ��� ã�°�