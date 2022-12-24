#include "3DGridMap.h"
_3DGridMap::_3DGridMap(float gridSize, int depth) :gridSize(gridSize), depth(depth) {
    this->map = new bool[depth * depth * depth];
    for (int i = 0; i < depth * depth * depth; i++) {
        map[i] = false;
    }
}
_3DGridMap::~_3DGridMap() {
    delete[] map;
}
void _3DGridMap::setDepth(int depth) {
    this->depth = depth;

}
int _3DGridMap::getDepth()
{
    return	depth;
}
void _3DGridMap::setGridSize(float gridSize) {

    this->gridSize = gridSize;
}
float _3DGridMap::getGridSize() {
    return gridSize;
}
bool& _3DGridMap::operator()(int _x, int _y, int _z) {
    return *(map + _x * depth * depth + _y * depth + _z);
}
bool _3DGridMap::getGrid(int x, int y, int z)
{
    return	(*this)(x, y, z);
}

void _3DGridMap::insertPoint(Point& p)
{
    int nx = floor(p.getX() / this->getGridSize());
    int ny = floor(p.getY() / this->getGridSize());
    int nz = floor(p.getZ() / this->getGridSize());
    if (nx >= 0 && ny >= 0 && nx >= 0 && nx < depth && ny < depth && nz < depth) {
        *(map + nx * depth * depth + ny * depth + nz) = true;
    }
}
void _3DGridMap::insertPointCloud(PointCloud& pc)
{
    for (int i = 0; i < pc.getpointNumber(); i++) {
        insertPoint(pc.getPoints()[i]);
    }
}
bool _3DGridMap::loadMap(string fileName) {
    delete[] map;
    ifstream myfile;
    string word;
    string line;
    string line2;
    myfile.open(fileName);
    if (myfile.is_open()) {
        getline(myfile, line);
        getline(myfile, line2);
        depth = stoi(line);
        gridSize = stof(line2);
        int i = 1;
        int x = 0, y = 0, z = 0;
        while (myfile >> word) {
            if (i % 3 == 1)
            {
                x = stoi(word);
            }
            if (i % 3 == 2)
            {
                y = stoi(word);
            }
            if (i % 3 == 0)
            {
                z = stoi(word);
                (*this)(x, y, z) = true;
            }
            i++;
        }
        myfile.close();
        cout << "Load completely." << endl;
        return true;
    }
    else
        return false;
}
bool _3DGridMap::saveMap(string fileName)
{
    fstream myfile;
    myfile.open(fileName, ios::out);
    if (myfile.is_open()) {
        myfile << this->depth << endl << this->gridSize << endl;
        for (int n = 0; n < depth; n++) {
            for (int p = 0; p < depth; p++) {
                for (int b = 0; b < depth; b++) {
                    if (*(map + n * depth * depth + p * depth + b) == true) {
                        myfile << n << " " << p << " " << b << endl;
                    }
                }
            }
        }
        
        myfile.close();
        cout << "Saved completely." << endl;
        return true;
    }
    else {
        return    false;
    }
}