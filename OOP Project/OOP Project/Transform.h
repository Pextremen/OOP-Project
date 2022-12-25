#pragma once
#include "PointCloud.h"

class Transform :public PointCloud {
private:
	double angles[3];  /*!<Holds three angle values, these angles will be used in rotation.*/
	double trans[3]; /*!<Holds the distances between the origins of two coordinate axes.*/  
	double transMatrix[4][4]; /*!<Creates the transformation matrix, transMatrix is a combination of rotationMatrix and trans*/ 
	double rotationMatrix[3][3]; /*!<Creates the rotation matrix*/ 

public:
	//! Constructor of Transform Class
	Transform();
	void setAngles(double, double, double);
	double* getAngles();
	void setTrans(double, double, double);
	double* getTrans();
	void setRotation(double angles[]);
	void setRotation(double rotation[3][3]);
	void setTranslation();
	Point doTransform(Point p);
	PointCloud doTransform(PointCloud& pc);
};
