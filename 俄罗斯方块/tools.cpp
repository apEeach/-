#include"tools.h"
#include<Windows.h>
#include<iostream>

//控制台大小
void setWindowSize(const int& cols, const int& lines)
{
	system("title=俄罗斯方块");
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
	system(cmd);
}

//设置文本颜色	
void setColor(const int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorID);
}

//光标位置
void setCursorPosition(const int& x, const int& y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
