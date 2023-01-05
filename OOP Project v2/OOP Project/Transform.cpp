#include "Transform.h"
Transform::Transform() {
    angles << 0, 0, 0;
    trans << 0, 0, 0;
    transMatrix << 0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0,
        0, 0, 0, 0;
    rotationMatrix << 0, 0, 0,
        0, 0, 0,
        0, 0, 0;
}

void Transform::setAngles(double a, double b, double c)
{
    ///Sets angles
    angles << a, b, c;
}

Eigen::Vector3d* Transform::getAngles()
{
    ///Returns angles
    return &angles;
}

void Transform::setTrans(double a, double b, double c) {
    trans << a, b, c;
}

Eigen::Vector3d* Transform::getTrans()
{
    return &trans;
}

void Transform::setRotation(double ang[3]) {
    ///Creates the rotationMatrix by performing the rotation operation
    //alfa = angles[2] || beta = angles[1] || gama = angles[0] 
    rotationMatrix << cos(ang[2]) * cos(ang[1]), (cos(ang[2]) * sin(ang[1]) * sin(ang[0])) - (sin(ang[2]) * cos(ang[0])), (cos(ang[2]) * sin(ang[1]))* cos(ang[0]) + (sin(ang[2]) * sin(ang[0])),
        sin(ang[2])* cos(ang[1]), (sin(ang[2]) * sin(ang[1]) * sin(ang[0])) + (cos(ang[2]) * cos(ang[0])), (sin(ang[2]) * sin(ang[1]) * cos(ang[0])) - (cos(ang[2]) * sin(ang[0])),
        -sin(ang[1]), cos(ang[1])* sin(ang[0]), cos(ang[1])* cos(ang[0]);

}
void Transform::setRotation(Eigen::Vector3d ang) {
    ///Creates the rotationMatrix
    rotationMatrix << cos(ang(2)) * cos(ang(1)), (cos(ang(2)) * sin(ang(1)) * sin(ang(0)) - (sin(ang(2)) * cos(ang(0)))), (cos(ang(2)) * sin(ang(1)) * cos(ang(0)) + (sin(ang(2)) * sin(ang(0)))),
        sin(ang(2))* cos(ang(1)), (sin(ang(2)) * sin(ang(1)) * sin(ang(0))) + (cos(ang(2)) * cos(ang(0))), (sin(ang(2)) * sin(ang(1)) * cos(ang(0))) - (cos(ang(2)) * sin(ang(0))),
        -sin(ang(1)), cos(ang(1))* sin(ang(0)), cos(ang(1))* cos(ang(0));
}
void Transform::setRotation(double rotation[3][3]) {
    ///Creates the rotationMatrix
    rotationMatrix(0, 0) = rotation[0][0];
    rotationMatrix(0, 1) = rotation[0][1];
    rotationMatrix(0, 2) = rotation[0][2];
    rotationMatrix(1, 0) = rotation[1][0];
    rotationMatrix(1, 1) = rotation[1][1];
    rotationMatrix(1, 2) = rotation[1][2];
    rotationMatrix(2, 0) = rotation[2][0];
    rotationMatrix(2, 1) = rotation[2][1];
    rotationMatrix(2, 2) = rotation[2][2];
}
void Transform::setTranslation(Eigen::Vector3d tr)
{
    //! transMatrix is a combination of rotationMatrix and trans
    //R R R T 
    //R R R T
    //R R R T
    //0 0 0 1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            transMatrix(i, j) = rotationMatrix(i, j);
        }
    }
    for (int i = 0; i < 3; i++) {
        transMatrix(i, 3) = tr(i);
    }
    // aktarma 3 son satir
    transMatrix(3, 0) = 0;
    transMatrix(3, 1) = 0;
    transMatrix(3, 2) = 0;
    transMatrix(3, 3) = 1;
}

Point Transform::doTransform(Point p) {
    ///Converts received points. 
    //old: X Y Z 1
    double oldPoint[4] = { p.getX(),p.getY(),p.getZ(),1 };
    //new: X Y Z 1 
    double newPoint[4] = { 0 };
    //matris çarpýmý
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            newPoint[i] += (transMatrix(i, j) * oldPoint[j]);
        }
    }
    //The new matrix obtained will be transferred to the new point
    Point originPoint;
    originPoint.setX(newPoint[0]);
    originPoint.setY(newPoint[1]);
    originPoint.setZ(newPoint[2]);
    return originPoint;
}

PointCloud Transform::doTransform(PointCloud& pc) {
    ///Converts the imported point cloud.
    PointCloud newPointCloud(pc.getpointNumber()); ///Creates same size empty PointCloud
    for (int i = 0; i < pc.getpointNumber(); i++) {
        newPointCloud.getPoints()[i] = doTransform(pc.getPoints()[i]);
    }
    return    newPointCloud;
}
