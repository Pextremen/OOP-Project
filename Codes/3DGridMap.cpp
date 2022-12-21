#include "3DGridMap.h"
_3DGridMap::_3DGridMap()
{
	long long int x = depth / 0.001;
}

void _3DGridMap::setDepth(double depth)
{
	this->depth = depth;
}

int _3DGridMap::getDepth()
{
	return	depth;
}

void _3DGridMap::insertPointCloud(PointCloud& pc)
{
	//this->getPoints() = this->getPoints() + pc.getPoints();
}
void _3DGridMap::setGridSize(float gridSize) {

	this->gridSize = gridSize;
}
float _3DGridMap::getGridSize() {
	return gridSize;
}
void _3DGridMap::insertPoint(Point& p)
{


}

const bool _3DGridMap::getGrid(int x, int y, int z)
{
	return	NULL;
}

bool _3DGridMap::loadMap(string fileName)
{
	return	NULL;

}

bool _3DGridMap::saveMap(string fileName)
{
	return	NULL;
}