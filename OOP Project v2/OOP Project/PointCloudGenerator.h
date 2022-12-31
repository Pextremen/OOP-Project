#pragma once

class PointCloudGenerator {
private:
	Transform transform;
public:
	PointCloudGenerator();
	PointCloud capture();
	PointCloud captureFor();
};