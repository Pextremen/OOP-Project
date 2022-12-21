#pragma once
#include "PointCloud.h"
//#define size 100000
class _3DGridMap :public PointCloud {
private:
	bool* map;
	float gridSize;
	int depth;
public:
	_3DGridMap();
	void setDepth(double depth);
	int getDepth();
	void setGridSize(float gridSize);
	float getGridSize();
	void insertPointCloud(PointCloud& pc);
	void insertPoint(Point& p);
	const bool getGrid(int x, int y, int z);
	bool loadMap(string fileName);
	bool saveMap(string fileName);
};