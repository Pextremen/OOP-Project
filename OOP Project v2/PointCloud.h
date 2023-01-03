///using vector
#pragma once
#include"Point.h"
#include <vector>
using namespace std;
class PointCloud {
private:
	vector<Point> points; /// vector of points
	int pointNumber; /// size of vector 
public:
	PointCloud(int pointNumber = 0);
	PointCloud(PointCloud&);
	void setpointNumber(int pointNumber);
	int getpointNumber();
	vector<Point>& getPoints();
	void setPoints(int, Point);
	PointCloud operator +(const PointCloud&);
	PointCloud  operator =(const PointCloud&);
};
