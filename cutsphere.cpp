#include "cutsphere.h"
#include <math.h>

CutSphere::CutSphere() {}

CutSphere::~CutSphere() {}

void CutSphere::draw(Sculptor &t)
{
    for (int i = xcenter - radius; i < xcenter + radius; i++) {
        for (int j = ycenter - radius; j < ycenter + radius; j++) {
            for (int k = zcenter - radius; k < zcenter + radius; k++) {
                float eq = sqrt(pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2));
                if (eq <= radius) {
                    t.cutVoxel(i, j, k);
                }
            }
        }
    }
}

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
}
