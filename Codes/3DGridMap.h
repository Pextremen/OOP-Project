#pragma once
#include "PointCloud.h"
class _3DGridMap :public PointCloud {
private:
//	bool map[][][];
	float gridSize;
	int depth;
public:
	_3DGridMap();
	void setDepth();
	int getDepth();
	void insertPointCloud(PointCloud& pc);
	void insertPoint(Point& p);
	const bool getGrid(int x, int y, int z);
	bool loadMap(string fileName);
	bool saveMap(string fileName);
}; 