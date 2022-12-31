#include <iostream>
#include"Transform.h"
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
#include"Point.h"
#include"PointCloud.h"

using namespace std;
void Transform_Recorder_Test() {
	cout << "*****Transform_&_Recorder_Test*****" << endl;
	cout << "-----------------------------------" << endl;
	Transform T, T1, T2, T3;
	DepthCamera d("cam.txt");
	DepthCamera d1("cam1.txt");
	DepthCamera d2("cam2.txt");
	DepthCamera d3("cam3.txt");
	PointCloud pc, pc1, pc2, pc3;
	pc = d.capture();
	pc1 = d1.capture();
	pc2 = d2.capture();
	pc3 = d3.capture();
	//pc için
	double rotation0[3][3] = { {-0.7076050, 0.0065031, -0.7065783 },
							   {0.7066082, 0.0065134, -0.7075750},
							   {0.0000008, -0.9999576, -0.0092041} };
	double rotation1[3][3] = { { -0.6638364, -0.0068830, 0.7478462},
							   {-0.7478778, 0.0061099, -0.6638082 },
							   {-0.0000002, -0.9999576, -0.0092036} };
	double rotation2[3][3] = { {0.8762180, 0.0044351, -0.4818945},
							   {0.4819149, -0.0080638, 0.8761809 },
							   {0.0000001, -0.9999577, -0.0092030} };
	double rotation3[3][3] = { {0.3597052, -0.0085871, 0.9330265 },
							   {-0.9330660, -0.0033108, 0.3596900},
							   {0.0000003, -0.9999576, -0.0092033} };
	T.setRotation(rotation0);
	T1.setRotation(rotation1);
	T2.setRotation(rotation2);
	T3.setRotation(rotation3);
	T.setTrans(1.95704, 1.93000, 1.05707);
	T1.setTrans(-1.91288, 1.94412, 1.05465);
	T2.setTrans(1.96978, -1.94622, 1.05264);
	T3.setTrans(-1.87445, -1.95027, 1.06432);
	T.setTranslation();
	T1.setTranslation();
	T2.setTranslation();
	T3.setTranslation();
	PointCloud finalcloud;
	PointCloud A, B;
	A = T.doTransform(pc) + T1.doTransform(pc1);
	B = T2.doTransform(pc2) + T3.doTransform(pc3);
	finalcloud = A + B;
	PointCloudRecorder recorder("final.txt");
	recorder.save(finalcloud);
	cout << "End of Transform_Recorder_Test" << endl;
	cout << "\n\n";
}