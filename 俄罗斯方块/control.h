#ifndef CONTROL_H
#define CONTROL_H

#include"point.h"
#include<vector>

class Control
{
public:

	Control():b_x(18),b_y(10)
	{
		show.emplace_back(16, 7);	//上
		show.emplace_back(17, 7);
		show.emplace_back(18, 7);
		show.emplace_back(19, 7);
		show.emplace_back(20, 7);
		show.emplace_back(21, 7);

		show.emplace_back(16, 14);	//上
		show.emplace_back(17, 14);
		show.emplace_back(18, 14);
		show.emplace_back(19, 14);
		show.emplace_back(20, 14);
		show.emplace_back(21, 14);
	}

	void playGame();				//开始游戏
	void updataScore(int score);	//更新分数
	void showMenu();				//显示菜单，地图左侧
	void nextBlock(const int ID);	//打印下一个方块
	void clearForceBlock();			//清除预测方块

private:
	std::vector<Point> show;		//右侧预测框
	std::vector<Point> forceBlock;	    //预测方块
	int b_x, b_y;					//预测方块的轴点坐标
};

#endif // !CONTROL_H

