#include "PointCloud.h"
using namespace std;

PointCloud::PointCloud(int pointNumber) {
    ///constructor
    this->points.resize(pointNumber);  //resize() changes the size of vector
}

PointCloud::PointCloud(PointCloud& p) {
    /// Copy constructor
    pointNumber = p.getpointNumber();
    this->points = p.points;
}
//! Sets the number of points according to the entered input.
void PointCloud::setpointNumber(int newpointNumber)
{
    this->points.resize(newpointNumber);
}

int PointCloud::getpointNumber() {
    /// return pointNumber(size of vector) 
    return this->points.size();
}

vector<Point>& PointCloud::getPoints() {
    /// returns vector
    return this->points;
}

void PointCloud::setPoints(int i, Point p) {
    /// assign value to vector
    this->points[i] = p;
}

PointCloud PointCloud::operator+(const PointCloud& p) {
    /// add two PointCloud
    PointCloud temp;
    temp.points.resize(this->points.size() + p.points.size());
    copy(this->points.begin(), this->points.end(), temp.points.begin());
    copy(p.points.begin(), p.points.end(), temp.points.begin() + this->points.size());
    return temp;
}

PointCloud PointCloud::operator=(const PointCloud& p) {
    /// equal operator overloading
    this->points = p.points;
    return *this;
}
