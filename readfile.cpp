#include "readfile.h"
#include "sculptor.h"
#include "putvoxel.h"
#include "cutvoxel.h"
#include "putbox.h"
#include "cutbox.h"
#include "putellipsoid.h"
#include "cutellipsoid.h"
#include "putsphere.h"
#include "cutsphere.h"
#include <iostream>
#include <fstream>
#include <sstream>

ReadFile::ReadFile(string filename) {
    ifstream file;
    string line;
    stringstream stream;

    file.open(filename);

    if(!file) {
        std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
        return;
    }

    while(file.good()){
        getline(file, line);

        stream.clear();
        stream.str(line);
        stream >> line;

        if (line.compare("dim") == 0) {
            stream >> dx >> dy >> dz;
            objSculptor = new Sculptor(dx, dy, dz);
        } else if (line.compare("putvoxel") == 0) {
            int x, y, z;
            float r, g, b, a;
            stream >> x >> y >> z >> r >> g >> b >> a;
            figure.push_back(new PutVoxel(x, y, z, r, g, b, a));
        } else if (line.compare("cutvoxel") == 0) {
            int x, y, z;
            stream >> x >> y >> z;
            figure.push_back(new CutVoxel(x, y, z));
        } else if (line.compare("putbox") == 0) {
            int x0, x1, y0, y1, z0, z1;
            float r, g, b, a;
            stream >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figure.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
        } else if (line.compare("cutbox") == 0) {
            int x0, x1, y0, y1, z0, z1;
            stream >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figure.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
        } else if (line.compare("putsphere") == 0) {
            int x, y, z, radius;
            float r, g, b, a;
            stream >> x >> y >> z >> radius >> r >> g >> b >> a;
            figure.push_back(new PutSphere(x, y, z, radius, r, g, b, a));
        } else if (line.compare("cutsphere") == 0) {
            int x, y, z, radius;
            stream >> x >> y >> z >> radius;
            figure.push_back(new CutSphere(x, y, z, radius));
        } else if(line.compare("putellipsoid") == 0) {
            int x, y, z, rx, ry, rz;
            float r, g, b, a;
            stream >> x >> y >> z >> rx >> ry >> rz >> r >> g >> b >> a;
            figure.push_back(new PutEllipsoid(x, y, z, rx, ry, rz, r, g, b, a));
        } else if(line.compare("cutellipsoid") == 0){
            int x, y, z, rx, ry, rz;
            stream >> x >> y >> z >> rx >> ry >> rz;
            figure.push_back(new CutEllipsoid(x, y, z, rx, ry, rz));
        }
    }

    for(int i=0; i < figure.size(); i++)
        figure[i]->draw(*objSculptor);

    file.close();
}

ReadFile::~ReadFile(){}
