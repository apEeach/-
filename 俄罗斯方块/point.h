#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point():x(0),y(0){}
	Point(const int &X,const int &Y):x(X),y(Y){}
	void print();		//��ӡ��
	void clear();		//�����
	int getX();			//��ȡx������
	int getY();			//��ȡy������
	void color(int colorID);	//����ɫ

private:
	int x, y;
};

#endif // !POINT_H
