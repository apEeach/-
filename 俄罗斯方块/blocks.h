#ifndef BLOCKS_H
#define BLOCKS_H

#include "point.h"
#include "tools.h"
#include "map.h"
#include<vector>

class Block
{
public:
	Block():b_x(7),b_y(1),blockType(1)
	{
	}

	void createID(const int ID);	//生成序号
	void createBlock(int blockID);	//生成俄罗斯方块
	void printBlock();		//打印俄罗斯方块
	void clearBlock();		//清除俄罗斯方块
	void move();			//自然下落
	void changeShape();		//变形
	void leftMove();		//左移
	void rightMove();		//右移
	int** saveBlock(int** mapArr);	//保存结点到地图数组中
	bool isCollision(int** mapArr);	//发生碰撞
	bool leftBoundary(int** mapArr);	//左边界碰撞
	bool rightBoundary(int** mapArr);	//右边界碰撞
	bool isLegal(Point& p);	//点是否合法

private:
	std::vector<Point> block;		//方块
	int b_x, b_y;					//方块轴心坐标
	int blockType;					//方块的类型
};	

#endif // !BLOCKS_H

