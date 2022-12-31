#pragma once
#include "PointCloud.h"
#include <string>
#include<fstream>
#include <sstream>
using namespace std;

class DepthCamera :public PointCloud {
private:
//! String file name to be read or written
	string fileName;
public:
	DepthCamera(string = "");
	void setfileName(string);
	string getfileName();
	PointCloud capture();
	PointCloud captureFor();
};
