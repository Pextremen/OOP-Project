#pragma once
#include "PointCloud.h"
#include <string>
using namespace std;
class PointCloudRecorder:public PointCloud {
private:
	string fileName;
public:
	PointCloudRecorder();
	void setfileName();
	string getfileName();
	bool save(const PointCloud& pc);
};