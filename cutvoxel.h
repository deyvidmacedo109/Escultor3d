#ifndef CUTVOXEL_H
#define CUTVOXEL_H

#include "figurageometrica.h"

class CutVoxel : public FiguraGeometrica
{
private:
    int x, y, z;
public:
    CutVoxel();
    ~CutVoxel();
    void draw(Sculptor &t);
    CutVoxel(int x, int y, int z);
};

#endif // CUTVOXEL_H
