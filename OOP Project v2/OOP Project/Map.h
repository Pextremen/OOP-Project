#pragma once
#include "PointCloud.h"
class Map {
public:
	//! pure virtual function of Map
	virtual void insertPointCloud(PointCloud& pc) = 0;
	//! pure virtual function of Map
	virtual void insertPoint(Point& p) = 0;
	//! pure virtual function of Map
	virtual bool loadMap(string) = 0;
	//! pure virtual function of Map
	virtual bool saveMap(string) = 0;
};
