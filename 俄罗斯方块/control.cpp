#include"control.h"
#include"map.h"
#include"blocks.h"
#include"tools.h"
#include<ctime>
#include<Windows.h>
#include<conio.h>
#include<iostream>

//开始游戏
void Control::playGame()
{
	setWindowSize(24,26);
	int blockID;
	blockID = rand() % 19 + 1;
	//初始化地图
	Map m;
	m.InitMap();
	//右侧显示
	showMenu();

	while (!m.Order())
	{
		//更新分数
		updataScore(m.getScore());
		//生成方块
		Block* a = new Block;
		a->createID(blockID);
		a->createBlock(blockID);
		a->printBlock();

		//显示下一个方块
		blockID = rand() % 19 + 1;
		clearForceBlock();
		nextBlock(blockID);

		char ch;
		//一个方块的移动
		while (!a->isCollision(m.getArr()))
		{
			//监听键盘输入
			if (_kbhit())
			{
				ch = _getch();
				switch (ch)
				{
					//方向键
				case -32:
					ch = _getch();
					switch (ch)
					{
					case 72:	//上
						a->changeShape();
						break;
					case 75:	//左
						if (!a->leftBoundary(m.getArr()))
						{
							a->leftMove();
						}
						break;
					case 77:	//右
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
		//到达最终位置的方块保存到地图数组中
		a->saveBlock(m.getArr());
		//消去满的行（如果有）
		m.clearCols();

		delete a;
	}

	setCursorPosition(7, 23);
	std::cout << "游戏结束！\n";
}

//更新分数
void Control::updataScore(int score)
{
	setCursorPosition(20, 4);
	std::cout << score;
}

//显示菜单
void Control::showMenu()
{
	setCursorPosition(16, 4);
	std::cout << "分数:";

	setCursorPosition(16, 6);
	std::cout << "下一个方块:";

	for (auto point : show)
	{
		point.color(1);
	}
}

//打印下一个方块
void Control::nextBlock(const int ID)
{
	switch (ID)
	{
	case 1:			/* ■■
					   ■■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 2:			/* ■
					   ■■■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 3:			/*   ■
						 ■
					   ■■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y + 1));
		break;
	case 4:			/* ■■■
						   ■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y + 1));
		break;
	case 5:			/* ■■
					   ■
					   ■   */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 6:			/*     ■
				   ■■■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 7:			/* ■■
						 ■
						 ■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 8:			/* ■■■
					   ■	  */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y + 1));
		break;
	case 9:			/* ■
					   ■
					   ■■   */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x + 1, b_y + 1));
		break;
	case 10:		/* ■■
						 ■■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 11:		/*   ■
					   ■■
					   ■	*/
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y + 1));
		break;
	case 12:		/*   ■■
					   ■■	  */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 13:		/* ■
					   ■■
						 ■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 14:		/*  ■
					  ■■■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		break;
	case 15:		/*   ■
					   ■■
						 ■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		break;
	case 16:		/* ■■■
						 ■   */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x - 1, b_y));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		break;
	case 17:		/* ■
				       ■■
				       ■   */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x + 1, b_y));
		break;
	case 18:		/* ■
					   ■
					   ■
					   ■ */
		forceBlock.emplace_back(Point(b_x, b_y));
		forceBlock.emplace_back(Point(b_x, b_y - 1));
		forceBlock.emplace_back(Point(b_x, b_y + 1));
		forceBlock.emplace_back(Point(b_x, b_y + 2));
		break;
	case 19:		/* ■■■■ */
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

//清除方块
void Control::clearForceBlock()
{
	for (auto point : forceBlock)
	{
		point.clear();
	}
	forceBlock.clear();
}
