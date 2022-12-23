#include "Point.h"

Point::Point(double x, double y, double z):x(x),y(y),z(z){}
double Point::getX(){
	return this->x;
}

double Point::getY(){
	return this->y;
}

double Point::getZ(){
	return this->z;
}
void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }
void Point::setZ(double z) { this->z = z; }


double Point::distance(const Point& p) const{
	double distance = pow((this->x - p.x), 2) + pow((this->y - p.y), 2) + pow((this->z - p.z), 2);
	return pow(distance, 0.5);
}

bool Point::operator==(const Point& p){
	if (this->x == p.x && this->y == p.y && this->z == p.z) { return true; }
	else { return false; }
}