#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class Point {
private:
	double x, y, z;
public:
	Point(double x = 0, double y = 0, double z = 0);
	double getX();
	double getY();
	double getZ();
	void setX(double);
	void setY(double);
	void setZ(double);
	double distance(const Point&)const;
	bool operator==(const Point&);
};