#pragma once
#include"Point.h"
class PointCloud {
private:
	Point* points;
	int pointNumber;
public:
	PointCloud(int pointNumber=0);
	PointCloud(PointCloud&);
	void setpointNumber(int pointNumber);
	int getpointNumber();

	PointCloud* operator +(const PointCloud&);
	void operator =(const PointCloud&);
	Point* getPoints();
};