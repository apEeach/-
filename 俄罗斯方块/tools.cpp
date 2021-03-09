#include"tools.h"
#include<Windows.h>
#include<iostream>

//����̨��С
void setWindowSize(const int& cols, const int& lines)
{
	system("title=����˹����");
	char cmd[30];
	sprintf_s(cmd, "mode con cols=%d lines=%d", cols * 2, lines);
	system(cmd);
}

//�����ı���ɫ	
void setColor(const int colorID)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),colorID);
}

//���λ��
void setCursorPosition(const int& x, const int& y)
{
	COORD position;
	position.X = x * 2;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
