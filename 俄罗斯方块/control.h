#ifndef CONTROL_H
#define CONTROL_H

#include"point.h"
#include<vector>

class Control
{
public:

	Control():b_x(18),b_y(10)
	{
		show.emplace_back(16, 7);	//��
		show.emplace_back(17, 7);
		show.emplace_back(18, 7);
		show.emplace_back(19, 7);
		show.emplace_back(20, 7);
		show.emplace_back(21, 7);

		show.emplace_back(16, 14);	//��
		show.emplace_back(17, 14);
		show.emplace_back(18, 14);
		show.emplace_back(19, 14);
		show.emplace_back(20, 14);
		show.emplace_back(21, 14);
	}

	void playGame();				//��ʼ��Ϸ
	void updataScore(int score);	//���·���
	void showMenu();				//��ʾ�˵�����ͼ���
	void nextBlock(const int ID);	//��ӡ��һ������
	void clearForceBlock();			//���Ԥ�ⷽ��

private:
	std::vector<Point> show;		//�Ҳ�Ԥ���
	std::vector<Point> forceBlock;	    //Ԥ�ⷽ��
	int b_x, b_y;					//Ԥ�ⷽ����������
};

#endif // !CONTROL_H

