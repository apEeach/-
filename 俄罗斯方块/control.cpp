#include"control.h"
#include"map.h"
#include"blocks.h"
#include"tools.h"
#include<ctime>
#include<Windows.h>
#include<conio.h>
#include<iostream>

//��ʼ��Ϸ
void Control::playGame()
{
	setWindowSize(24,26);
	int blockID;
	blockID = rand() % 19 + 1;
	//��ʼ����ͼ
	Map m;
	m.InitMap();
	//�Ҳ���ʾ
	showMenu();

	while (!m.Order())
	{
		//���·���
		updataScore(m.getScore());
		//���ɷ���
		Block* a = new Block;
		a->createID(blockID);
		a->createBlock(blockID);
		a->printBlock();

		//��ʾ��һ������
		blockID = rand() % 19 + 1;
		clearForceBlock();
		nextBlock(blockID);

		char ch;
		//һ��������ƶ�
		while (!a->isCollision(m.getArr()))
		{
			//������������
			if (_kbhit())
			{
				ch = _getch();
				switch (ch)
				{
					//�����
				case -32:
					ch = _getch();
					switch (ch)
					{
					case 72:	//��
						a->changeShape();
						break;
					case 75:	//��
						if (!a->leftBoundary(m.getArr()))
						{
							a->leftMove();
						}
						break;
					case 77:	//��
						if (!a->rightBoundary(m.getArr()))
						{
							a->rightMove();
						}
						break;
					case 80:
						if (!a->isCollision(m.getArr()))
						{
							a->move();
							Sleep(100);
						}
						break;
					default:
						break;
					}
					break;
				case 27:
					exit(0);
					break;
				}
				Sleep(15);
			}
			if (!a->isCollision(m.getArr()))
			{
				a->move();
				Sleep(400);
			}
		}
		//��������λ�õķ��鱣�浽��ͼ������
		a->saveBlock(m.getArr());
		//��ȥ�����У�����У�
		m.clearCols();

		delete a;
	}

	setCursorPosition(7, 23);
	std::cout << "��Ϸ������\n";
}

//���·���
void Control::updataScore(int score)
{
	setCursorPosition(20, 4);
	std::cout << score;
}

//��ʾ�˵�
void Control::showMenu()
{
	setCursorPosition(16, 4);
	std::cout << "����:";

	setCursorPosition(16, 6);
	std::cout << "��һ������:";

	for (auto point : show)
	{
		point.color(1);
	}
}

//��ӡ��һ������
void Control::nextBlock(const int ID)
{
	switch (ID)
	{
	case 1:			/* ����
					   ���� */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 2:			/* ��
					   ������ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 3:			/*   ��
						 ��
					   ���� */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y + 1));
		break;
	case 4:			/* ������
						   �� */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y + 1));
		break;
	case 5:			/* ����
					   ��
					   ��   */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 6:			/*     ��
				   ������ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 7:			/* ����
						 ��
						 �� */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 8:			/* ������
					   ��	  */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y + 1));
		break;
	case 9:			/* ��
					   ��
					   ����   */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x + 1, b_y + 1));
		break;
	case 10:		/* ����
						 ���� */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 11:		/*   ��
					   ����
					   ��	*/
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y + 1));
		break;
	case 12:		/*   ����
					   ����	  */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 13:		/* ��
					   ����
						 �� */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 14:		/*  ��
					  ������ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		break;
	case 15:		/*   ��
					   ����
						 �� */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		break;
	case 16:		/* ������
						 ��   */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		break;
	case 17:		/* ��
				       ����
				       ��   */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		break;
	case 18:		/* ��
					   ��
					   ��
					   �� */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x, b_y + 2));
		break;
	case 19:		/* �������� */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x + 2, b_y));
		break;
	default:
		break;
	}

	for (auto point : forceBlock)
	{
		point.color(ID);
	}
}

//�������
void Control::clearForceBlock()
{
	for (auto point : forceBlock)
	{
		point.clear();
	}
	forceBlock.clear();
}
