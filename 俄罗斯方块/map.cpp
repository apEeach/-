#include "map.h"
#include<iostream>

int Map::score = 0;

int  Map::getScore() { return score; }

//���Ƶ�ͼ�߽�
void Map::InitMap()		
{
	for (auto point : initMap)
	{
		setCursorPosition(point.getX(), point.getY());
		point.print();
	}
}

//��������
int** Map::getArr()		
{
	return mapArr;
}

//������ȥ
void Map::clearCols()
{
	//�ж����������Ƿ��������У�
	for (int i = 20; i >= 1; i--)
	{
		int flag = true;		//������Ƿ���Ҫ��ȥ

		for (int j = 1; j < 14; j++)
		{
			//��һ������һ����û�з��飬���ʾ������ȥ
			if (mapArr[j][i] == 0)
			{
				flag = false;
				break;
			}
		}

		//��ȥ����һ�е�Ԫ��
		if (flag)
		{
			for (int k = 1; k < 14; k++)
			{
				mapArr[i][k] = 0;
			}
			score += 100;	//��������
			updataArry(i);	//���µ�ͼ����
			updataMap();	//���µ�ͼ
			clearCols();	//�ж��µĵ�ͼ�Ƿ�������
			break;
		}
	}
}

//��������
void Map::updataArry(const int &pos)
{
	for (int i = pos; i > 1; i--)
	{
		for (int j = 1; j < 14; j++)
		{
			mapArr[j][i] = mapArr[j][i - 1];
		}
	}
	//���һ����Ϊ0
	for (int i = 1; i < 14; i++)
	{
		mapArr[i][1] = 0;
	}
}

//���µ�ͼ
void Map::updataMap() 
{
	//������Ϊ��
	if (!mapBlock.empty())
	{
		mapBlock.clear();
	}
	//��ͼ�������ݸ�������ͼ����������
	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			if (mapArr[i][j] == 1)
			{
				setCursorPosition(i, j);
				std::cout << "��";
			}
			else
			{
				setCursorPosition(i, j);
				std::cout << "  ";
			}
		}
	}
}

// �Ƿ񳬳���ͼ�Ϸ�
bool Map::Order()
{
	for (int i = 1; i < 14; i++)
	{
		//����ͼ�������Ϸ�һ����Ԫ�أ����ʾԽ��
		if (mapArr[i][1] == 1)
		{
			return true;
		}
	}
	return false;
}

