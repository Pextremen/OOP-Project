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
PointCloud DepthCamera::captureFor() {
    Transform T;
    PointCloud pc;
    pc = capture();
    if (fileName == "cam.txt") {
        double rotation0[3][3] = { {-0.7076050, 0.0065031, -0.7065783 },
                                {0.7066082, 0.0065134, -0.7075750},
                                {0.0000008, -0.9999576, -0.0092041} };
        T.setRotation(rotation0);
        Eigen::Vector3d tr;
        tr << 1.95704, 1.93000, 1.05707;
        T.setTranslation(tr);
        pc = T.doTransform(pc);
    }
    if (fileName == "cam1.txt") {
        double rotation1[3][3] = { { -0.6638364, -0.0068830, 0.7478462},
                               {-0.7478778, 0.0061099, -0.6638082 },
                               {-0.0000002, -0.9999576, -0.0092036} };
        T.setRotation(rotation1);
        Eigen::Vector3d tr1;
        tr1 << -1.91288, 1.94412, 1.05465;
        T.setTranslation(tr1);
        pc = T.doTransform(pc);
    }
    if (fileName == "cam2.txt") {
        double rotation2[3][3] = { {0.8762180, 0.0044351, -0.4818945},
                                   {0.4819149, -0.0080638, 0.8761809 },
                                   {0.0000001, -0.9999577, -0.0092030} };
        T.setRotation(rotation2);
        Eigen::Vector3d tr2;
        tr2 << 1.96978, -1.94622, 1.05264;
        T.setTranslation(tr2);
        pc = T.doTransform(pc);
    }
    if (fileName == "cam3.txt") {
        double rotation3[3][3] = { {0.3597052, -0.0085871, 0.9330265 },
                                {-0.9330660, -0.0033108, 0.3596900},
                                {0.0000003, -0.9999576, -0.0092033} };
        T.setRotation(rotation3);
        Eigen::Vector3d tr3;
        tr3 << -1.87445, -1.95027, 1.06432;
        T.setTranslation(tr3);
        pc = T.doTransform(pc);
    }
    return pc;
};
