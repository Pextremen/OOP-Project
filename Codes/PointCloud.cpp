#include "PointCloud.h"

PointCloud::PointCloud(int pointNumber) {
	this->pointNumber = pointNumber;
	points = new Point[pointNumber];
}

PointCloud::PointCloud(PointCloud& p) {
	
}

void PointCloud::setpointNumber(int pointNumber) {
	this->pointNumber = pointNumber;
}

int PointCloud::getpointNumber() { return this->pointNumber; }

PointCloud* PointCloud::operator+(const PointCloud& p) {

	return nullptr;
}

void PointCloud::operator=(const PointCloud& p) {
	this->points = p.points;
	this->pointNumber = p.pointNumber;
}
Point* PointCloud::getPoints()
{
	return points;
}
