#pragma once
#include"Transform.h"
#include"PointCloud.h"

class PointCloudGenerator
{
	//! Object of Transform
	Transform transform;	
public:
	//! When the capture function is called, it reads the points and assigns them to the created point cloud object. Returns the point cloud. This process is a simulation of the camera. Points are taken from a file rather than a camera.
	virtual PointCloud capture() = 0;//Bu fonksiyon pure virtual fonksiyondur.
	//! First of all, it will do the same with the capture function; however, the point cloud will be returned after it has been transformed with the transform object of which it is a member.
	virtual PointCloud captureFor() = 0;//Bu fonksiyon pure virtual fonksiyondur.
};
