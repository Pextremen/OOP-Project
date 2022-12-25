#include"Transform.h"
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
#include"Point.h"
#include"PointCloud.h"
#include"3DGridMap.h"
void PointCloudTest();
void DepthCamera_Test();
void Transform_Recorder_Test();
void _3DGridMap_Test();
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