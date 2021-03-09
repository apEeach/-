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

	void createID(const int ID);	//�������
	void createBlock(int blockID);	//���ɶ���˹����
	void printBlock();		//��ӡ����˹����
	void clearBlock();		//�������˹����
	void move();			//��Ȼ����
	void changeShape();		//����
	void leftMove();		//����
	void rightMove();		//����
	int** saveBlock(int** mapArr);	//�����㵽��ͼ������
	bool isCollision(int** mapArr);	//������ײ
	bool leftBoundary(int** mapArr);	//��߽���ײ
	bool rightBoundary(int** mapArr);	//�ұ߽���ײ
	bool isLegal(Point& p);	//���Ƿ�Ϸ�

private:
	std::vector<Point> block;		//����
	int b_x, b_y;					//������������
	int blockType;					//���������
};	

#endif // !BLOCKS_H

