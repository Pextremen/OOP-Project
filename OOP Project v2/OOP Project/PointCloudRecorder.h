#pragma once
#include <string>
#include<fstream>
using namespace std;
class PointCloudRecorder :{
private:
	string fileName; ///name of file
public:
	PointCloudRecorder(string);
	void setfileName(string);
	string getfileName();
	bool save(PointCloud& pc);
};