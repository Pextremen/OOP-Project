#include <iostream>
#include"DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
using namespace std;

void DepthCamera_Test() {
	PointCloud pc1;
	DepthCamera d("cam.txt");
	pc1 = d.capture();
	cout << "*********DepthCamera Test**********" << endl;
	cout << "-----------------------------------" << endl;
	cout<<"pointNumber for cam.txt: " << pc1.getpointNumber() << endl;
	cout << pc1.getPoints()[0].getX() <<" ";
	cout << pc1.getPoints()[0].getY() << " ";
	cout << pc1.getPoints()[0].getZ() << " ";
	cout << endl;
	cout << pc1.getPoints()[1].getX() << " ";
	cout << pc1.getPoints()[1].getY() << " ";
	cout << pc1.getPoints()[1].getZ() << " ";
	cout << endl << "End of DepthCamera_Test" << endl;
	cout << "\n\n";
}