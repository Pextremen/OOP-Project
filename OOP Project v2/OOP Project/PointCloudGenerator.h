#pragma once
#include"Transform.h"
#include"PointCloud.h"

class PointCloudGenerator
{
	Transform transform;	
public:
	virtual PointCloud capture() = 0;//pure virtual function
	virtual PointCloud captureFor() = 0;//pure virtual function
};
