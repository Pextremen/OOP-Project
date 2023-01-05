#pragma once
#include "PointCloud.h"
class Map {
public:
	virtual void insertPointCloud(PointCloud& pc) = 0;//pure virtual function
	virtual void insertPoint(Point& p) = 0;//pure virtual function
	virtual bool loadMap(string) = 0;//pure virtual function
	virtual bool saveMap(string) = 0;//pure virtual function
};
