#pragma once
#include <list>
#include"Point.h"
class PointCloud {
private:
	//! list of points
	list<PointCloud> points;
	//int pointNumber;                    v2 don't have that attribute
public:
	PointCloud(int pointNumber = 0);
	PointCloud(PointCloud&);
//	void setpointNumber(int pointNumber); v2 don't have that attribute
//	int getpointNumber();                 v2 don't have that attribute
	Point* getPoints();
	void setPoints(int, Point);
	PointCloud operator +(const PointCloud&);
	PointCloud  operator =(const PointCloud&);
};
