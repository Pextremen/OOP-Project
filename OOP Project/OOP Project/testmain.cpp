#include <iostream>
#include "Point.h"
#include "PointCloud.h"
#include "3DGridMap.h"
#include "DepthCamera.h"
#include "PointCloudRecorder.h"
#include "Transform.h"
int main() {
	ifstream cam1;
	string word;
	string line;
	string line2;
	cam1.open("cam1.txt");
	getline(cam1, line);
	getline(cam1, line);
	int a = stod(line);
	int j = 0;
	cout << a << endl;





	cout << endl << endl;
	return 0;
}