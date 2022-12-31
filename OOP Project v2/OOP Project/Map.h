#pragma once
class Map {
public:
	Map();
	void setMap();
	getMap();
	void insertPointCloud(PointCloud& pc);
	void insertPoint(Point& p);
	bool loadMap(fileName);
	bool saveMap(fileName);
};