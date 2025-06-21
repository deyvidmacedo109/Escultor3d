#ifndef PUTSPHERE_H
#define PUTSPHERE_H

#include "figurageometrica.h"

class PutSphere : public FiguraGeometrica
{
private:
    int xcenter;
    int ycenter;
    int zcenter;
    int radius;
    float r, g, b, a;
public:
    PutSphere();
    ~PutSphere();
    void draw(Sculptor &t);
    PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
};

#endif // PUTSPHERE_H
