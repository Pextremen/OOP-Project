#include<iostream>
#include<cmath>
using namespace std;
class Point {
private:
	double x;
	double y;
	double z;
public:

	Point(double x=0.0, double y=0.0, double z=0.0);
	double getX();
	double getY();
	double getZ();
	void setX(double x);
	void setY(double y);
	void setZ(double z);
	double distance(const Point&)const;
	bool operator==(const Point&);
};