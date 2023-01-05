#pragma once
#include "PointCloud.h"
class Map {
public:
	virtual void insertPointCloud(PointCloud& pc) = 0;
	virtual void insertPoint(Point& p) = 0;
	virtual bool loadMap(string) = 0;
	virtual bool saveMap(string) = 0;
};
