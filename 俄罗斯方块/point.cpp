#include "point.h"
#include "tools.h"
#include<iostream>

//��ӡ��
void Point::print()
{
	setCursorPosition(x, y);
	std::cout << "��";
}

//�����
void Point::clear()
{
	setCursorPosition(x, y);
	std::cout << "  ";
}

//����ɫ
void Point::color(int colorID)
{
	switch (colorID)
	{
	case 1:
		setColor(8);
		print();	//��ӡ����
		break;
	case 2:
	case 3:
	case 4:
	case 5:
		setColor(10);
		print();	//��ӡ����
		break;
	case 6:
	case 7:
	case 8:
	case 9:
		setColor(12);
		print();	//��ӡ����
		break;
	case 10:
	case 11:
		setColor(14);
		print();	//��ӡ����
		break;
	case 12:
	case 13:
		setColor(15);
		print();	//��ӡ����
		break;
	case 14:
	case 15:
	case 16:
	case 17:
		setColor(13);
		print();	//��ӡ����
		break;
	case 18:
	case 19:
		setColor(9);
		print();	//��ӡ����
		break;
	default:
		break;
	}
}

//��ȡx������
int Point::getX() { return x; }

//��ȡy������
int Point::getY() { return y; }