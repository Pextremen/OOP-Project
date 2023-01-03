#pragma once
#include "MapperInterface.h"
class Map {
public:
	Map();
	virtual void insertPointCloud(PointCloud& pc) = 0;
	virtual void insertPoint(Point& p) = 0;
	virtual bool loadMap(fileName) = 0;
	virtual bool saveMap(fileName) = 0;
};