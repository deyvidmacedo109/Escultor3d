#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H

#include "figurageometrica.h"

class CutEllipsoid : public FiguraGeometrica
{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int rx;
    int ry;
    int rz;
public:
    CutEllipsoid();
    ~CutEllipsoid();
    void draw(Sculptor &t);
    CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
};

#endif // CUTELLIPSOID_H
