#ifndef READFILE_H
#define READFILE_H

#include "figurageometrica.h"
#include "sculptor.h"
#include <vector>
#include <string>

using namespace std;

class ReadFile
{
private:
    int dx, dy, dz;
public:
    ReadFile(string filename);
    virtual ~ReadFile();
    vector<FiguraGeometrica*> figure;
    Sculptor *objSculptor;
};

#endif // READFILE_H
