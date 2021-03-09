#ifndef MAP_H
#define MAP_H

#include<vector>
#include"point.h"
#include"tools.h"

const int N = 50;	

class Map
{
public:
	Map()
	{
		//数组初始化
		mapArr = new int* [N];
		for (int i = 0; i < N; i++)
		{
			mapArr[i] = new int[N];
			for (int j = 0; j < N; j++)
			{
				mapArr[i][j] = 0;
			}
		}

		//地图描点(0,0),(0,21),(14,0),(14.21)
		initMap.emplace_back(Point(0, 0));	//左
		initMap.emplace_back(Point(0, 1));
		initMap.emplace_back(Point(0, 2));
		initMap.emplace_back(Point(0, 3));
		initMap.emplace_back(Point(0, 4));
		initMap.emplace_back(Point(0, 5));
		initMap.emplace_back(Point(0, 6));
		initMap.emplace_back(Point(0, 7));
		initMap.emplace_back(Point(0, 8));
		initMap.emplace_back(Point(0, 9));
		initMap.emplace_back(Point(0, 10));
		initMap.emplace_back(Point(0, 11));
		initMap.emplace_back(Point(0, 12));
		initMap.emplace_back(Point(0, 13));
		initMap.emplace_back(Point(0, 14));
		initMap.emplace_back(Point(0, 15));
		initMap.emplace_back(Point(0, 16));
		initMap.emplace_back(Point(0, 17));
		initMap.emplace_back(Point(0, 18));
		initMap.emplace_back(Point(0, 19));
		initMap.emplace_back(Point(0, 20));
		initMap.emplace_back(Point(0, 21));

		initMap.emplace_back(Point(14, 0));	//右
		initMap.emplace_back(Point(14, 1));
		initMap.emplace_back(Point(14, 2));
		initMap.emplace_back(Point(14, 3));
		initMap.emplace_back(Point(14, 4));
		initMap.emplace_back(Point(14, 5));
		initMap.emplace_back(Point(14, 6));
		initMap.emplace_back(Point(14, 7));
		initMap.emplace_back(Point(14, 8));
		initMap.emplace_back(Point(14, 9));
		initMap.emplace_back(Point(14, 10));
		initMap.emplace_back(Point(14, 11));
		initMap.emplace_back(Point(14, 12));
		initMap.emplace_back(Point(14, 13));
		initMap.emplace_back(Point(14, 14));
		initMap.emplace_back(Point(14, 15));
		initMap.emplace_back(Point(14, 16));
		initMap.emplace_back(Point(14, 17));
		initMap.emplace_back(Point(14, 18));
		initMap.emplace_back(Point(14, 19));
		initMap.emplace_back(Point(14, 20));
		initMap.emplace_back(Point(14, 21));

		initMap.emplace_back(Point(1, 0));	//上
		initMap.emplace_back(Point(2, 0));
		initMap.emplace_back(Point(3, 0));
		initMap.emplace_back(Point(4, 0));
		initMap.emplace_back(Point(5, 0));
		initMap.emplace_back(Point(6, 0));
		initMap.emplace_back(Point(7, 0));
		initMap.emplace_back(Point(8, 0));
		initMap.emplace_back(Point(9, 0));
		initMap.emplace_back(Point(10, 0));
		initMap.emplace_back(Point(11, 0));
		initMap.emplace_back(Point(12, 0));
		initMap.emplace_back(Point(13, 0));

		initMap.emplace_back(Point(1, 21));	//下
		initMap.emplace_back(Point(2, 21));
		initMap.emplace_back(Point(3, 21));
		initMap.emplace_back(Point(4, 21));
		initMap.emplace_back(Point(5, 21));
		initMap.emplace_back(Point(6, 21));
		initMap.emplace_back(Point(7, 21));
		initMap.emplace_back(Point(8, 21));
		initMap.emplace_back(Point(9, 21));
		initMap.emplace_back(Point(10, 21));
		initMap.emplace_back(Point(11, 21));
		initMap.emplace_back(Point(12, 21));
		initMap.emplace_back(Point(13, 21));
	}

	void InitMap();			//绘制地图边界	
	int** getArr();			//返回数组
	void clearCols();		//行满消去
	void updataArry(const int &pos);	//更新数组
	void updataMap();		//更新地图
	static int getScore();	//返回分数
	bool Order();			//是否超出地图上方

	~Map()
	{
		if (mapArr != NULL)
		{
			delete[] mapArr;
		}
	}

private:
	std::vector<Point> initMap;		//初始化地图
	std::vector<Point> mapBlock;	//地图内保存的方块
	int **mapArr;					//二维数组存放方块的信息，数组值为1表示有方块，为0则表示没有
	static int score;				//分数
};

#endif // !MAP_H

