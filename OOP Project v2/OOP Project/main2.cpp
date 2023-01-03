#include"Transform.h"
#include"DepthCamera.h"
#include"PointCloudRecorder.h"
#include"Point.h"
#include"PointCloud.h"
#include "PointCloudGenerator.h"
#include "MapperInterface.h"

int main() {
    MapperInterface Interface("final.txt");
    PointCloudGenerator* G = new DepthCamera("cam.txt");
    PointCloudGenerator* G1 = new DepthCamera("cam1.txt");
    PointCloudGenerator* G2 = new DepthCamera("cam2.txt");
    PointCloudGenerator* G3 = new DepthCamera("cam3.txt");
    Interface.addGenerator(G);
    Interface.addGenerator(G1);
    Interface.addGenerator(G2);
    Interface.addGenerator(G3);
    Interface.generate();
    Interface.recordPointCloud();
}