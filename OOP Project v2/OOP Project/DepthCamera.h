#pragma once
#include "PointCloudGenerator.h"
#include"Transform.h"
#include "PointCloud.h"
#include <string>
#include<fstream>
#include <sstream>
using namespace std;
class DepthCamera :public PointCloudGenerator {
private:
	//! String file name to be read or written
	string fileName;
public:
	//! Constructor
	DepthCamera(string = "");
	void setfileName(string);
	string getfileName();
	PointCloud capture();
	PointCloud captureFor();
};
