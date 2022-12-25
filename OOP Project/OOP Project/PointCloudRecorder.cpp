#include "PointCloudRecorder.h"

PointCloudRecorder::PointCloudRecorder(string fileName) :fileName(fileName) {
	///Constructor
}

void PointCloudRecorder::setfileName(string fileName) {
	/// set file name
	this->fileName = fileName;
}

string PointCloudRecorder::getfileName()
{
	/// return file name
	return	this->fileName;
}

bool PointCloudRecorder::save(PointCloud& pc) {
	/// save file
	fstream myFile; 
	myFile.open(getfileName(), ios::out);
	if (myFile.is_open()) {
		myFile << "///XYZRGB" << endl;
		myFile << pc.getpointNumber() << endl;
		for (int i = 0; i < pc.getpointNumber(); i++) {
			myFile << pc.getPoints()[i].getX() << " " << pc.getPoints()[i].getY() << " " << pc.getPoints()[i].getZ() << endl;
		}
		myFile.close();
		cout << "Saved completely" << endl;
		return true;
	}
	else
		return false;
}
