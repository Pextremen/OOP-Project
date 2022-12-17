#include "Transform.h"
double rotationMatrix[3][3];
Transform::Transform()
{
	for (int i = 0; i < 3; i++)
	{
		angles[i] = 0;
		trans[i] = 0;
     }
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			transMatrix[i][j] = 0;
		}
	}
}

void Transform::setAngles(double a, double b, double c)
{
	angles[0] = a;
	angles[1] = b;
	angles[2] = c;
}

double* Transform::getAngles()
{
	return angles;
}

void Transform::setTrans(double a, double b, double c){
	trans[0] = a;
	trans[1] = b;
	trans[2] = c;
}

double* Transform::getTrans()
{
	return trans;
}

void Transform::setRotation(double angles[3])
{

	rotationMatrix[0][0] = cos(angles[2]) * cos(angles[1]);
	rotationMatrix[0][1] = (cos(angles[2]) * sin(angles[1]) * sin(angles[0])) - (sin(angles[2]) * cos(angles[0]));
	rotationMatrix[0][2] = (cos(angles[2]) * sin(angles[1])) * cos(angles[0]) + (sin(angles[2]) * sin(angles[0]));
	rotationMatrix[1][0] = sin(angles[2]) * cos(angles[1]);
	rotationMatrix[1][1] = (sin(angles[2]) * sin(angles[1]) * sin(angles[0])) + (cos(angles[2]) * cos(angles[0]));
	rotationMatrix[1][2] = (sin(angles[2]) * sin(angles[1]) * cos(angles[0])) - (cos(angles[2]) * sin(angles[0]));
	rotationMatrix[2][0] = -sin(angles[1]);
	rotationMatrix[2][1] = cos(angles[1]) * sin(angles[0]);
	rotationMatrix[2][2] = cos(angles[1]) * cos(angles[0]);

}

void Transform::setTranslation(double trans[3])
{
	transMatrix[3][0] = 0;
	transMatrix[3][1] = 0;
	transMatrix[3][2] = 0;
	transMatrix[3][3] = 1;

}

Point Transform::doTransform(Point p)
{

	return	p;
}

PointCloud Transform::doTransform(PointCloud pc)
{
	return	pc;
}
