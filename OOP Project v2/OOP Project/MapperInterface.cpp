#include "MapperInterface.h"
#include<vector>
using namespace std;

MapperInterface::MapperInterface()
{
   generators = vector<PointCloudGenerator*>();
}

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
    if (recorder)
        return recorder->save(pointCloud);
    return false;
}

bool MapperInterface::recordMap()
{
   // mapi kaydet
}

bool MapperInterface::insertMap()
{
    // mape nokta bulutlarını ekle
    //nesnenin insert fonksiyonunu çağır
}
