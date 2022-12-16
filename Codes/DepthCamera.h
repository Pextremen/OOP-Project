#pragma once
#include "PointCloud.h"
#include <string>
#include<fstream>
using namespace std;

class DepthCamera:public PointCloud{
private:
	string fileName;
public:
	DepthCamera(string="");
	void setfileName(string);
	string getfileName();
	PointCloud capture();
};
