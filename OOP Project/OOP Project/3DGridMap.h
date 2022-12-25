#pragma once
#include "PointCloud.h"
#include<fstream>
#include<string>
class _3DGridMap :public PointCloud {
private:
	bool* map;///declaration array
	float gridSize;
	int depth;
public:
	_3DGridMap(float = 0, int = 0);
	~_3DGridMap();
	void setDepth(int);
	int getDepth();
	void setGridSize(float gridSize);
	float getGridSize();
	bool& operator()(int, int, int);
	bool getGrid(int x, int y, int z);
	void insertPointCloud(PointCloud& pc);
	void insertPoint(Point& p);
	bool loadMap(string fileName);
	bool saveMap(string fileName);
};
