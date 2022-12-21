#include"Point.h"
class PointCloud {
private:
	Point* points;
	int pointNumber;
public:
	PointCloud(int pointNumber=0);
	PointCloud(PointCloud&);
	void setpointNumber(int pointNumber);
	int getpointNumber();
	Point* getPoints();
	void setPoints(int, Point);
	PointCloud operator +(const PointCloud&);
	PointCloud  operator =(const PointCloud&);
};