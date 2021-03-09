#include "point.h"
#include "tools.h"
#include<iostream>

//打印点
void Point::print()
{
	setCursorPosition(x, y);
	std::cout << "■";
}

//清除点
void Point::clear()
{
	setCursorPosition(x, y);
	std::cout << "  ";
}

//点颜色
void Point::color(int colorID)
{
	switch (colorID)
	{
	case 1:
		setColor(8);
		print();	//打印方块
		break;
	case 2:
	case 3:
	case 4:
	case 5:
		setColor(10);
		print();	//打印方块
		break;
	case 6:
	case 7:
	case 8:
	case 9:
		setColor(12);
		print();	//打印方块
		break;
	case 10:
	case 11:
		setColor(14);
		print();	//打印方块
		break;
	case 12:
	case 13:
		setColor(15);
		print();	//打印方块
		break;
	case 14:
	case 15:
	case 16:
	case 17:
		setColor(13);
		print();	//打印方块
		break;
	case 18:
	case 19:
		setColor(9);
		print();	//打印方块
		break;
	default:
		break;
	}
}

//获取x轴坐标
int Point::getX() { return x; }

//获取y轴坐标
int Point::getY() { return y; }