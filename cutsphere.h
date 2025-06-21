#ifndef CUTSPHERE_H
#define CUTSPHERE_H

#include "figurageometrica.h"

class CutSphere : public FiguraGeometrica
{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int radius;
public:
    CutSphere();
    ~CutSphere();
    void draw(Sculptor &t);
    CutSphere(int xcenter, int ycenter, int zcenter, int radius);
};

#endif // CUTSPHERE_H
