#ifndef PUTBOX_H
#define PUTBOX_H

#include "figurageometrica.h"

class PutBox : public FiguraGeometrica
{
private:
    int x0;
    int x1;
    int y0;
    int y1;
    int z0;
    int z1;
    float r, g, b, a;
public:
    PutBox();
    ~PutBox();
    void draw(Sculptor &t);
    PutBox(int x0, int x1, int y0, int y1, int z0, int z1, float r, float g, float b, float a);
};

#endif // PUTBOX_H
