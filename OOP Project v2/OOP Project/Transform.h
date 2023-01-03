#pragma once
#include<Eigen/Dense>
class Transform {
private:
	Eigen::Vector3d angles;  /*!<Holds three angle values, these angles will be used in rotation.*/
	Eigen::Vector3d trans; /*!<Holds the distances between the origins of two coordinate axes.*/
	Eigen::Matrix4d transMatrix; /*!<Creates the transformation matrix, transMatrix is a combination of rotationMatrix and trans*/
	Eigen::Matrix3d rotationMatrix; /*!<Creates the rotation matrix*/

public:
	//! Constructor of Transform Class
	Transform();
	void setAngles(double, double, double);
	Eigen::Vector3d* getAngles();
	void setTrans(double, double, double);
	Eigen::Vector3d* getTrans();
	void setRotation(double angles[]);
	void setRotation(Eigen::Vector3d);
	void setTranslation(Eigen::Vector3d);
	Point doTransform(Point p);
	PointCloud doTransform(PointCloud& pc);
};