#include "DepthCamera.h"
//! Constructor 
DepthCamera::DepthCamera(string fileName) :fileName(fileName) {}
//! Changes the filename
void DepthCamera::setfileName(string fileName)
{
	this->fileName = fileName;
}
//! Reaches the name of the instantaneously read or written file.
string DepthCamera::getfileName()
{
	return fileName;
}
//! When the capture function is called, it reads the points and assigns them to the created point cloud object. Returns the point cloud. This process is a simulation of the camera. Points are taken from a file rather than a camera.
PointCloud DepthCamera::capture() { //cam1.txt
    PointCloud temp;
    int i = 1;
    ifstream myFile;
    string word;
    string line;
    string line2;
    myFile.open(this->fileName);
    getline(myFile, line);
    getline(myFile, line);
    int a = stoi(line);
    int j = 0;
    temp.setpointNumber(a);
    while (myFile >> word) {
        if (i % 6 == 1)
        {
            temp.getPoints()[j].setX(stod(word));
        }
        if (i % 6 == 2)
        {
            temp.getPoints()[j].setY(stod(word));
        }
        if (i % 6 == 3)
        {
            temp.getPoints()[j].setZ(stod(word));
        }
        if (i % 6 == 4)
        {
        }
        if (i % 6 == 5)
        {
        }
        if (i % 6 == 0)
        {
            j++;
        }
        i++;
    }
    return temp;
}
