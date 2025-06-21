#ifndef PUTVOXEL_H
#define PUTVOXEL_H

#include "figurageometrica.h"

class PutVoxel : public FiguraGeometrica
{
private:
    int x, y, z;
    float r, g, b, a;
public:
    PutVoxel();
    ~PutVoxel();
    void draw(Sculptor &t);
    PutVoxel(int x, int y, int z, float r, float g, float b, float a);
};

#endif // PUTVOXEL_H
