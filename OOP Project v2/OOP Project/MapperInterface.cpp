#include "MapperInterface.h"

MapperInterface::MapperInterface()
{
   
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
    
    for (auto generator : generators)
    {
        auto cloud = generator->captureFor();
        pointCloud.push_back(cloud);
    }

    return !pointCloud.empty();
}

bool MapperInterface::recordPointCloud()
{
    if (recorder)
        return recorder->record(pointCloud);
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
