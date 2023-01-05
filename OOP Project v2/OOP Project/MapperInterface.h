#pragma once
#include <vector>
#include"PointCloudGenerator.h"
#include"PointCloud.h"
#include"Map.h"
#include "3DGridMap.h"
#include"PointCloudRecorder.h"

class MapperInterface {
private:
	PointCloud pointCloud; ///final cloud
	PointCloud patch;
	vector<PointCloudGenerator*> generators; ///vector for generators
	PointCloudRecorder* recorder;
    Map* map; /// to write-save map
public:
	MapperInterface(Map*, PointCloudRecorder*, vector<PointCloudGenerator*>);
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool recordPointCloud();
	bool recordMap();
	bool insertMap();
};
