#pragma once
#include "Transform.h"
#include "PointCloud.h"
class PointCloudGenerator {
	Transform transform;
public:
	PointCloudGenerator();
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
};