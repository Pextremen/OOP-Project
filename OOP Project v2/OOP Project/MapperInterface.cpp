#include "MapperInterface.h"

MapperInterface::MapperInterface(Map* map, PointCloudRecorder* rec, vector<PointCloudGenerator*> arr):map(map),
recorder(rec), generators(arr){}

void MapperInterface::addGenerator(PointCloudGenerator* generator)
{
    /// Adds generator elements to vector
    generators.push_back(generator);  
}

void MapperInterface::setRecorder(PointCloudRecorder* recorder)
{
    this->recorder = recorder;
}
bool MapperInterface::generate()
{
    /// captureFor function from all objects in generators member point clouds are provided by calling
   /// A point cloud is then added to the pointCloud member

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
    ///registers pointCloud
    recorder->save(pointCloud);
    return 1;
}

bool MapperInterface::insertMap() {
    
///renders point clouds on the map
   map->insertPointCloud(pointCloud);
   return 1;
}
bool MapperInterface::recordMap() {
   ///functions save pointCloud and map to file respectively
   map->saveMap("map.txt"); 
   return 1;
}
