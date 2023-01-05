#pragma once
#include"Transform.h"
#include"PointCloud.h"

class PointCloudGenerator
{
	Transform transform;	
public:

	PointCloudGenerator();
	virtual PointCloud capture() = 0;//Bu fonksiyon pure virtual fonksiyondur.
	virtual PointCloud captureFor() = 0;//Bu fonksiyon pure virtual fonksiyondur.
	~PointCloudGenerator();
};
