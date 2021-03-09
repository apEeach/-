#include "map.h"
#include<iostream>

int Map::score = 0;

int  Map::getScore() { return score; }

//绘制地图边界
void Map::InitMap()		
{
	for (auto point : initMap)
	{
		setCursorPosition(point.getX(), point.getY());
		point.print();
	}
}

//返回数组
int** Map::getArr()		
{
	return mapArr;
}

//行满消去
void Map::clearCols()
{
	//判断整个数组是否有满的行，
	for (int i = 20; i >= 1; i--)
	{
		int flag = true;		//标记行是否需要消去

		for (int j = 1; j < 14; j++)
		{
			//当一行中有一个点没有方块，则表示不能消去
			if (mapArr[j][i] == 0)
			{
				flag = false;
				break;
			}
		}

		//消去满的一行的元素
		if (flag)
		{
			for (int k = 1; k < 14; k++)
			{
				mapArr[i][k] = 0;
			}
			score += 100;	//分数增加
			updataArry(i);	//更新地图数组
			updataMap();	//更新地图
			clearCols();	//判断新的地图是否还有行满
			break;
		}
	}
}

//更新数组
void Map::updataArry(const int &pos)
{
	for (int i = pos; i > 1; i--)
	{
		for (int j = 1; j < 14; j++)
		{
			mapArr[j][i] = mapArr[j][i - 1];
		}
	}
	//最后一行置为0
	for (int i = 1; i < 14; i++)
	{
		mapArr[i][1] = 0;
	}
}

//更新地图
void Map::updataMap() 
{
	//容器不为空
	if (!mapBlock.empty())
	{
		mapBlock.clear();
	}
	//地图数组数据更新至地图方块容器中
	for (int i = 1; i < 14; i++)
	{
		for (int j = 1; j < 21; j++)
		{
			if (mapArr[i][j] == 1)
			{
				setCursorPosition(i, j);
				std::cout << "■";
			}
			else
			{
				setCursorPosition(i, j);
				std::cout << "  ";
			}
		}
	}
}

// 是否超出地图上方
bool Map::Order()
{
	for (int i = 1; i < 14; i++)
	{
		//当地图数组最上方一行有元素，则表示越界
		if (mapArr[i][1] == 1)
		{
			return true;
		}
	}
	return false;
}

