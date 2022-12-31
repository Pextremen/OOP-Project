#include"Transform.h"
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
#include"Point.h"
#include"PointCloud.h"
#include"3DGridMap.h"
//! Point ve PointCloud TEST
void PointCloudTest();
//! DepthCamera TEST
void DepthCamera_Test();
//! PointCloudRecorder and Transform TEST
void Transform_Recorder_Test();
//! _3DGridMap TEST
void _3DGridMap_Test();
//! Main Function
int main() {
#if 1
	PointCloudTest();
#endif
#if 1
	DepthCamera_Test();
#endif
#if 1
	Transform_Recorder_Test();
#endif
#if 1
	_3DGridMap_Test();
#endif
	return 0;
}
