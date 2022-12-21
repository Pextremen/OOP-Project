#include "DepthCamera.h"

DepthCamera::DepthCamera(string fileName) :fileName(fileName) {}

void DepthCamera::setfileName(string fileName)
{
	this->fileName = fileName;
}

string DepthCamera::getfileName()
{
	return fileName;
}
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


/*PointCloud DepthCamera::capture() {
	PointCloud tempCloud;

	string capfilename = this->fileName + ".txt";
	
	fstream myFile; //Dosyaya islemleri
	myFile.open(capfilename, ios::in); //dosya okuma
	if (myFile.is_open()) {
		string line;
		int i = 0;
		string tempX, tempY, tempZ, cx;
		getline(myFile, line); // ilk iki line önceden alýnýr
		getline(myFile, line);
		tempCloud.setpointNumber(stoi(line)); //ikinci line dizi boyutu belirleniyor

		while (getline(myFile, line)) { //her satiri line'e gonder
			stringstream ssin(line); //ssin fonksiyonu
			//string'i parcalama ve PointCloud a gönderme dizisine gonderme
			//böylece boþluklu line'ý parça parça alýcak
			ssin >> tempX;
			tempCloud.getPoints()[i].setX(stod(tempX));
			ssin >> tempY;
			tempCloud.getPoints()[i].setY(stod(tempY));
			ssin >> tempZ;
			tempCloud.getPoints()[i].setZ(stod(tempZ));
			i++;
		}
		myFile.close();
	}
	return tempCloud;
}*/