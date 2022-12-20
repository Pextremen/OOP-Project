#include <iostream>
#include "PointCloud.h"
using namespace std;
void PointCloudTest() {
    cout << "*****PointTest*****" << endl;
    Point p1(17, 13, 12);
    Point p2(3, 4, 5);
    Point p3(3, 4, 5);
    Point p4(6, 8, 10);
    cout << "p1: " << p1.getX()<<" " << p1.getY()<<" " << p1.getZ() << endl;
    p1.setX(1);
    p1.setY(5);
    p1.setZ(9);
    cout << "p1: " << p1.getX() << " " << p1.getY() << " " << p1.getZ() << endl;
    if (p2 == p3) {
        cout << "p2 and p3 are equal" << endl;
    }
    double distance = p3.distance(p4);
    cout << "Distance between p3 and p4 is: " << distance << endl;
    
    //Test 2
    cout << "*****PointCloudTest*****" << endl;
    PointCloud pc1(4), pc2(4);
    pc1.getPoints()[0] = p1;
    pc1.getPoints()[1] = p2;
    pc1.getPoints()[2] = p3;
    pc1.getPoints()[3] = p4;
    cout << "pc1" << endl;
    for (int i = 0; i < pc1.getpointNumber(); i++) {
        cout<<"(" << pc1.getPoints()[i].getX() << ", " << pc1.getPoints()[i].getY() << ", " << pc1.getPoints()[i].getZ()<<")" << endl;
    }
    cout << endl;
    PointCloud pc3;
    pc3 = pc1;
    cout << "pc3 = pc1" << endl;
    for (int i = 0; i < pc3.getpointNumber(); i++) {
        cout << "(" << pc3.getPoints()[i].getX() << ", " << pc3.getPoints()[i].getY() << ", " << pc3.getPoints()[i].getZ() << ")" << endl;
    }
    cout << endl;
    pc2 = pc1 + pc3;
    cout << "pc2 = pc1 + pc3" << endl;
    for (int i = 0; i < pc2.getpointNumber(); i++) {
        cout << "(" << pc2.getPoints()[i].getX() << ", " << pc2.getPoints()[i].getY() << ", " << pc2.getPoints()[i].getZ() << ")" << endl;
    }
    pc1.setpointNumber(5);
    Point p5(10, 20, 30);
    //pc1.getPoints()[4] = p5; 
    pc1.setPoints(4, p5);
    cout << "pc1" << endl;
    for (int i = 0; i < pc1.getpointNumber(); i++) {
        cout << "(" << pc1.getPoints()[i].getX() << ", " << pc1.getPoints()[i].getY() << ", " << pc1.getPoints()[i].getZ() << ")" << endl;
    }
}
