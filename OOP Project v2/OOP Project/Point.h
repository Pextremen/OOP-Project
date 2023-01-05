#pragma once
#include<iostream>
#include<cmath>
using namespace std;
class Point {
private:
	double x; /*!< x variable represents the (1.) x coordinate of the points */
	double y; /*!< y variable represents the (2.) y coordinate of the points */
	double z; /*!< z variable represents the (3.) z coordinate of the points */
public:
	//! Constructor of Point Class
	Point(double x = 0, double y = 0, double z = 0);
	double getX();
	double getY();
	double getZ();
	//! Sets the x value according to the entered input.
	void setX(double);
	//! Sets the y value according to the entered input.
	void setY(double);
	//! Sets the z value according to the entered input.
	void setZ(double);
	double distance(const Point&)const;
	//! Checks if two points are equal.
	bool operator==(const Point&);
};
