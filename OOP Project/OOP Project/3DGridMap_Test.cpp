#include <iostream>
#include"Transform.h"
#include"DepthCamera.h"
#include "PointCloudRecorder.h"
#include "Point.h"
#include "PointCloud.h"
#include "3DGridMap.h"

void _3DGridMap_Test() {
	cout << "***********3DGridMap_Test**********" << endl;
	cout << "-----------------------------------" << endl;
	_3DGridMap myGrid(1, 10);
	Point p1(1, 1, 2);
	Point p2(3, 4, 5);
	Point p3(3, 2, 5);
	Point p4(7, 8, 1);
	PointCloud pc1(4);
	pc1.getPoints()[0] = p1;
	pc1.getPoints()[1] = p2;
	pc1.getPoints()[2] = p3;
	pc1.getPoints()[3] = p4;
	myGrid.insertPointCloud(pc1);
	myGrid.saveMap("map.txt");
	_3DGridMap myGrid2;
	myGrid2.loadMap("map.txt");
	myGrid2.saveMap("map2.txt");
	cout << "End of _3DGridMap_Test" << endl;
	cout << "\n\n";
}