#include "MapperInterface.h"

MapperInterface::MapperInterface(Map* map, PointCloudRecorder* rec, vector<PointCloudGenerator*> arr):map(map),
recorder(rec), generators(arr){}

void MapperInterface::addGenerator(PointCloudGenerator* generator)
{
    generators.push_back(generator);
}

void MapperInterface::setRecorder(PointCloudRecorder* recorder)
{
    this->recorder = recorder;
}
bool MapperInterface::generate()
{
    // PointCloudGenerator nesnesi yok ya da eklenmemis.
    if (generators.empty())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < generators.size(); i++)
        {
            patch = generators[i]->captureFor();
            pointCloud = pointCloud + patch;
        }
        return true;
    }
}

bool MapperInterface::recordPointCloud()
{
    recorder->save(pointCloud);
    return 1;
}

bool MapperInterface::insertMap() {
   map->insertPointCloud(pointCloud);
   return 1;
}
bool MapperInterface::recordMap() {
   map->saveMap("map.txt"); //map'i kaydet
   return 1;
}
