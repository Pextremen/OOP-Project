#include "MapperInterface.h"

MapperInterface::MapperInterface(string fileName)
{
    recorder->setfileName(fileName);
}

void MapperInterface::addGenerator(PointCloudGenerator* generator)
{
    generators.push_back(generator);
}

void MapperInterface::setRecorder(PointCloudRecorder* recorder)
{

    this->recorder = recorder;
}

bool MapperInterface::generate() {
    for (int i = 0; i < generators.size(); i++) {
        pointCloud = pointCloud + generators[i]->captureFor();
    }
    return 1;
}

bool MapperInterface::recordPointCloud()
{
    recorder->save(pointCloud);
    return 1;
}

bool MapperInterface::recordMap() {
    //map->saveMap("map.txt");    // mapi kaydet
    return 1;
}

bool MapperInterface::insertMap() {
    //map->insertPointCloud(pointCloud);
    return 1;
}