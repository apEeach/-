#include "blocks.h"
#include<Windows.h>

//�������
void Block::createID(const int ID)
{
	blockType = ID;
}

//���ɶ���˹����
void Block::createBlock(int blockID)
{
	switch (blockID)
	{
	case 1:			/* ����
					   ���� */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x + 1, b_y));
		block.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 2:			/* ��
					   ������ */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x - 1, b_y));
		block.emplace_back(Point(b_x + 1, b_y));
		block.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 3:			/*   ��
					     ��
					   ���� */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x, b_y + 1));
		block.emplace_back(Point(b_x - 1, b_y + 1));
		break;
	case 4:			/* ������
					       �� */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x - 1, b_y));
		block.emplace_back(Point(b_x + 1, b_y));
		block.emplace_back(Point(b_x + 1, b_y + 1));
		break;
	case 5:			/* ����
					   ��
					   ��   */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x, b_y + 1));
		block.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 6:			/*     ��
					   ������ */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x - 1, b_y));
		block.emplace_back(Point(b_x + 1, b_y));
		block.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 7:			/* ����
						 ��
						 �� */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x, b_y + 1));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 8:			/* ������
					   ��	  */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x - 1, b_y));
		block.emplace_back(Point(b_x + 1, b_y));
		block.emplace_back(Point(b_x - 1, b_y + 1));
		break;
	case 9:			/* ��
				       ��
					   ����   */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x, b_y + 1));
		block.emplace_back(Point(b_x + 1, b_y + 1));
		break;
	case 10:		/* ����
				         ���� */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x + 1, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 11:		/*   ��
					   ����
					   ��	*/
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x - 1, b_y));
		block.emplace_back(Point(b_x - 1, b_y + 1));
		break;
	case 12:		/*   ����
				       ����	  */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x - 1, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x + 1, b_y - 1));
		break;
	case 13:		/* ��
				       ����
						 �� */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x - 1, b_y));
		block.emplace_back(Point(b_x, b_y + 1));
		block.emplace_back(Point(b_x - 1, b_y - 1));
		break;
	case 14:		/*  ��
					  ������ */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x - 1, b_y));
		block.emplace_back(Point(b_x + 1, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		break;
	case 15:		/*   ��
				       ����
					     �� */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x, b_y + 1));
		block.emplace_back(Point(b_x - 1, b_y));
		break;
	case 16:		/* ������
				         ��   */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x - 1, b_y));
		block.emplace_back(Point(b_x + 1, b_y));
		block.emplace_back(Point(b_x, b_y + 1));
		break;
	case 17:		/* ��
					   ����
				       ��   */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x, b_y + 1));
		block.emplace_back(Point(b_x + 1, b_y));
		break;
	case 18:		/* ��
					   ��
					   ��
					   �� */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x, b_y - 1));
		block.emplace_back(Point(b_x, b_y + 1));
		block.emplace_back(Point(b_x, b_y + 2));
		break;
	case 19:		/* �������� */
		block.emplace_back(Point(b_x, b_y));
		block.emplace_back(Point(b_x - 1, b_y));
		block.emplace_back(Point(b_x + 1, b_y));
		block.emplace_back(Point(b_x + 2, b_y));
		break;
	default:
		break;
	}
}

//��ӡ����˹����
void Block::printBlock()
{
	for (auto point : block)
	{
		if (point.getY() > 0)
		{
			point.color(blockType);
		}
	}
	//��궨λ�����½ǣ�����Ӱ�췽����Ӿ�Ч��
	setCursorPosition(23, 25);
}

//�������˹����
void Block::clearBlock()
{
	for (auto point : block)
	{
		if (point.getY() > 0)
		{
			point.clear();
		}
	}
	block.clear();
}

//��Ȼ����
void Block::move()
{
	clearBlock();
	++b_y;
	createBlock(blockType);
	printBlock();
}

//�����㵽��ͼ������
int** Block::saveBlock(int** mapArr)
{
	for (auto point : block)
	{
		mapArr[point.getX()][point.getY()] = 1;
	}
	return mapArr;
}

//����
void Block::changeShape()
{
	//ÿ�α��ξ��Ǹı䷽�������
	switch (blockType)
	{
	case 1:
		break;
	case 2:
		clearBlock();
		blockType = 3;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 2;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 3:
		clearBlock();
		blockType = 4;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 3;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 4:
		clearBlock();
		blockType = 5;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 4;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 5:
		clearBlock();
		blockType = 2;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 5;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 6:
		clearBlock();
		blockType = 7;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 6;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 7:
		clearBlock();
		blockType = 8;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 7;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 8:
		clearBlock();
		blockType = 9;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 8;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 9:
		clearBlock();
		blockType = 6;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 9;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 10:
		clearBlock();
		blockType = 11;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 10;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 11:
		clearBlock();
		blockType = 10;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 11;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 12:
		clearBlock();
		blockType = 13;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 12;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 13:
		clearBlock();
		blockType = 12;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 13;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 14:
		clearBlock();
		blockType = 15;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 14;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 15:
		clearBlock();
		blockType = 16;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 15;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 16:
		clearBlock();
		blockType = 17;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 16;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 17:
		clearBlock();
		blockType = 14;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 17;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 18:
		clearBlock();
		blockType = 19;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 18;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	case 19:
		clearBlock();
		blockType = 18;
		createBlock(blockType);
		for (auto point : block)
		{
			//���κ�ķ��鲻��Խ��
			if (!isLegal(point))
			{
				block.clear();
				blockType = 19;
				createBlock(blockType);
				printBlock();
				break;
			}
		}
		printBlock();
		break;
	default:
		break;
	}
}

//����
void Block::leftMove()
{
	clearBlock();
	--b_x;
	createBlock(blockType);
	Sleep(50);
	printBlock();
}

//����
void Block::rightMove()
{
	clearBlock();
	++b_x;
	createBlock(blockType);
	Sleep(50);
	printBlock();
}

//������ײ
bool Block::isCollision(int **mapArr)
{
	for (auto point : block)
	{
		if (mapArr[point.getX()][point.getY() + 1] == 1 || point.getY() == 20)
		{
			return true;
		}
	}
	return false;
}

//��߽���ײ
bool Block::leftBoundary(int** mapArr)
{
	for (auto point : block)
	{
		if (point.getX() == 1 || mapArr[point.getX() - 1][point.getY()] == 1)
		{
			return true;
		}
	}
	return false;
}

//�ұ߽���ײ
bool Block::rightBoundary(int** mapArr)
{
	for (auto point : block)
	{
		if (point.getX() == 13 || mapArr[point.getX()+1][point.getY()] == 1)
		{
			return true;
		}
	}
	return false;
}

//���Ƿ�Ϸ�
bool Block::isLegal(Point &p)
{
	if (p.getX() == 0 || p.getX() == 14 || p.getY() == 21)
	{
		return false;
	}
	return true;
}