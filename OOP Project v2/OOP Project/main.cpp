#include "MapperInterface.h"
#include <iostream>
#include"Transform.h"
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
#include"Point.h"
#include"PointCloud.h"
#include "PointCloudGenerator.h"

int main() {
    PointCloudRecorder recorder("final.txt");

    PointCloudGenerator* G;
    G = new DepthCamera("cam.txt");
    PointCloudGenerator* G1;
    G1 = new DepthCamera("cam1.txt");
    PointCloudGenerator* G2;
    G2 = new DepthCamera("cam2.txt");
    PointCloudGenerator* G3;
    G3 = new DepthCamera("cam3.txt");
    vector<PointCloudGenerator*> arr;
    arr.push_back(G);
    arr.push_back(G1);
    arr.push_back(G2);
    arr.push_back(G3);
    Map* map;
    map = new _3DGridMap(0.1, 10);

    MapperInterface Interface(map, &recorder, arr);
    Interface.generate();
    Interface.insertMap();
    Interface.recordPointCloud();
    Interface.recordMap();


    return 0;
}
