#pragma once
#include "PointCloud.h"

class Transform :public PointCloud {
private:
	double angles[3];
	double trans[3];
	double transMatrix[4][4];
public:
	Transform();
	void setAngles(double, double, double);
	double* getAngles();
	void setTrans(double, double, double);
	double* getTrans();
	void setRotation(double angles[]);
	void setTranslation(double trans[]);
	Point doTransform(Point p);
	PointCloud doTransform(PointCloud pc);
};
