#include "3DGridMap.h"
_3DGridMap::_3DGridMap(float gridSize, int depth) :gridSize(gridSize), depth(depth) {
    /// constructor
    this->map = new bool[depth * depth * depth];
    for (int i = 0; i < depth * depth * depth; i++) {
        map[i] = false;
    }
}
_3DGridMap::~_3DGridMap() {
    /// destructor
    delete[] map;
}
void _3DGridMap::setDepth(int newdepth) { 
    /// set depth(size of array)
    bool* tempmap = new bool[newdepth * newdepth * newdepth];
    for (int i = 0; i < depth * depth * depth; i++) {
        tempmap[i] = map[i];
    }
    delete[] map;
    int olddepth = this->depth;
    this->depth = newdepth;
    this->map = new bool[depth * depth * depth];
    for (int i = 0; i < olddepth; i++) {
        map[i] = tempmap[i];
    }
    delete[] tempmap;
}

int _3DGridMap::getDepth()
{
    /// return depth
    return	depth;
}
void _3DGridMap::setGridSize(float gridSize) {
    /// set grid size
    this->gridSize = gridSize;
}
float _3DGridMap::getGridSize() {
    /// return grid size
    return gridSize;
}
bool& _3DGridMap::operator()(int _x, int _y, int _z) {
    /// operator overloading
    return *(map + _x * depth * depth + _y * depth + _z);
}
bool _3DGridMap::getGrid(int x, int y, int z)
{   
    /// return grid
    return	(*this)(x, y, z);
}

void _3DGridMap::insertPoint(Point& p)
{
    /// insert a point
    int nx = int(floor(p.getX() / this->getGridSize()));
    int ny = int(floor(p.getY() / this->getGridSize()));
    int nz = int(floor(p.getZ() / this->getGridSize()));
    if (nx >= 0 && ny >= 0 && nx >= 0 && nx < depth && ny < depth && nz < depth) {
        (*this)(nx, ny, nz) = true;
    }
}
void _3DGridMap::insertPointCloud(PointCloud& pc)
{
    /// insert a pointcloud
    for (int i = 0; i < pc.getpointNumber(); i++) {
        insertPoint(pc.getPoints()[i]);
    }
}
bool _3DGridMap::loadMap(string fileName) {
    /// to store array from file
    string word;
    string line;
    string line2;
    fstream myfile; 
    myfile.open(fileName, ios::in);
    if (myfile.is_open()) {
        getline(myfile, line);
        getline(myfile, line2);
        setDepth(stoi(line));
        this->gridSize = stof(line2);
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
        cout << "Loaded completely" << endl;
        return true;
    }
    else
        return false;
}
bool _3DGridMap::saveMap(string fileName) {
    /// transfer array to file
    fstream myFile; 
    myFile.open(fileName, ios::out);
    int n = this->depth;
    if (myFile.is_open()) {
        myFile << this->depth << endl;
        myFile << this->gridSize << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if ((*this)(i, j, k) == true)
                        myFile << i << " " << j << " " << k << endl;
                }
            }
        }
        myFile.close();
        cout << "Saved completely" << endl;
        return true;
    }
    else
        return false;
}
