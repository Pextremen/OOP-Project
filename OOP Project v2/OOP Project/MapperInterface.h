#pragma once
#include <vector>
#include"PointCloudGenerator.h"
#include"PointCloud.h"
#include"Map.h"
#include "3DGridMap.h"
#include"PointCloudRecorder.h"

class MapperInterface {
private:
	PointCloud pointCloud; //final cloud
	PointCloud patch;
	vector<PointCloudGenerator*> generators; //
	PointCloudRecorder* recorder; //pc yazma için
    Map* map; //map yazma için
public:
	MapperInterface(Map*, PointCloudRecorder*, vector<PointCloudGenerator*>);
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool recordPointCloud();
	bool recordMap();
	bool insertMap();
};
