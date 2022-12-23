#include "PointCloudRecorder.h"

PointCloudRecorder::PointCloudRecorder(string fileName):fileName(fileName){}

void PointCloudRecorder::setfileName(string fileName){
	this->fileName = fileName;
}

string PointCloudRecorder::getfileName()
{
	return	this->fileName;
}

bool PointCloudRecorder::save(PointCloud& pc){
	fstream myFile; //Dosyaya islemleri
	myFile.open(getfileName(), ios::out);
	if (myFile.is_open()) {
		myFile << "///XYZRGB" << endl;
		myFile << getpointNumber() << endl;
		for (int i = 0; i < getpointNumber(); i++) {
			myFile << pc.getPoints()[i].getX() << " " << pc.getPoints()[i].getY() << " " << pc.getPoints()[i].getZ() << endl;
		}
		myFile.close();
		cout << "Saved completely" << endl;
		return true;
	}
	else
		return false;
}