#include "Transform.h"
Transform::Transform(){
	this->angles[3] = { 0 };
	this->trans[3] = { 0 };
	this->rotationMatrix[3][3] = { 0 };
	this->transMatrix[3][3] = { 0 };
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

void Transform::setRotation(double ang[3])
{
	//alfa = angles[2] || beta = angles[1] || gama = angles[0] 
	rotationMatrix[0][0] = cos(ang[2]) * cos(ang[1]);
	rotationMatrix[0][1] = (cos(ang[2]) * sin(ang[1]) * sin(ang[0])) - (sin(ang[2]) * cos(ang[0]));
	rotationMatrix[0][2] = (cos(ang[2]) * sin(ang[1])) * cos(ang[0]) + (sin(ang[2]) * sin(ang[0]));
	rotationMatrix[1][0] = sin(ang[2]) * cos(ang[1]);
	rotationMatrix[1][1] = (sin(ang[2]) * sin(ang[1]) * sin(ang[0])) + (cos(ang[2]) * cos(ang[0]));
	rotationMatrix[1][2] = (sin(ang[2]) * sin(ang[1]) * cos(ang[0])) - (cos(ang[2]) * sin(ang[0]));
	rotationMatrix[2][0] = -sin(ang[1]);
	rotationMatrix[2][1] = cos(ang[1]) * sin(ang[0]);
	rotationMatrix[2][2] = cos(ang[1]) * cos(ang[0]);
}

void Transform::setTranslation(double tr[3])
{
	//transMatrix, rotationMatrix ve trans'ın bırlesiminden olusur:
	//R R R T 
	//R R R T
	//R R R T
	//0 0 0 1
	for (int i = 0; i < 3; i++){//aktarma 1
		for (int j = 0; j < 3; j++){
			transMatrix[i][j] = rotationMatrix[i][j];
		}
	}
	for (int i = 0; i < 3; i++) { //aktarma 2
		transMatrix[i][3] = tr[i];
	}
	// aktarma 3 son satir
	transMatrix[3][0] = 0;
	transMatrix[3][1] = 0;
	transMatrix[3][2] = 0;
	transMatrix[3][3] = 1;
}

Point Transform::doTransform(Point p){
	//old: X Y Z 1
	double oldPoint[4] = { p.getX(),p.getY(),p.getZ(),1 };
	//new: X Y Z 1 
	double newPoint[4] = { 0 };
	//matris çarpımı
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			newPoint[i] += (transMatrix[i][j] * oldPoint[j]);
		}
	}
	//elde edilen yeni matris yeni noktaya aktarılacak
	Point originPoint;
	originPoint.setX(newPoint[0]);
	originPoint.setY(newPoint[1]);
	originPoint.setZ(newPoint[2]);
	return originPoint;
}

PointCloud Transform::doTransform(PointCloud pc){
	PointCloud newPointCloud(pc.getpointNumber()); //ayni boyutta empty PointCloud
	for (int i = 0; i < pc.getpointNumber(); i++) {
		newPointCloud.getPoints()[i] = doTransform(pc.getPoints()[i]);
	}
	return	newPointCloud;
}
