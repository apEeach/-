#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point():x(0),y(0){}
	Point(const int &X,const int &Y):x(X),y(Y){}
	void print();		//打印点
	void clear();		//清除点
	int getX();			//获取x轴坐标
	int getY();			//获取y轴坐标
	void color(int colorID);	//点颜色

private:
	int x, y;
};

#endif // !POINT_H
