#include "DepthCamera.h"

DepthCamera::DepthCamera(string fileName):fileName(fileName){}

void DepthCamera::setfileName(string fileName)
{
	this->fileName = fileName;
}

string DepthCamera::getfileName()
{
	return fileName;
}
PointCloud DepthCamera::capture() {
    PointCloud temp;
    int i = 1;
    ifstream cam1;
    string word;
    string line;
    string line2;
    cam1.open("cam1.txt");
    getline(cam1, line);
    getline(cam1, line);
    int a = stoi(line);
    int j = 0;
    temp.setpointNumber(a);
    while (cam1 >> word) {
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