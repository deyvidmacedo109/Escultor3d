#include "sculptor.h"
#include <iostream>
#include <fstream>
#include <math.h>

Sculptor::Sculptor(int _nx, int _ny, int _nz)
{
    nx = _nx; // planos
    ny = _ny; // linhas
    nz = _nz; // colunas
    
    // alocação de memória do primeiro ponteiro 
    v = new Voxel **[nx];

    for (int i = 0; i < nx; i++) {
        // alocação do segundo ponteiro
        v[i] = new Voxel *[ny];
    
        for (int j = 0; j < ny; j++) {
            // alocação do terceiro ponteiro
            v[i][j] = new Voxel[nz];
            
            // defindo variáveis com valor padrão 
            for (int k = 0; k < nz; k++) {
                v[i][j][k].r = 0; 
                v[i][j][k].g = 0;
                v[i][j][k].b = 0;
                v[i][j][k].a = 0;
                v[i][j][k].show = false;
            }
        }
    }
}

Sculptor::~Sculptor()
{
    // liberação de memória dos ponteiros
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            delete[] v[i][j]; // libera o terceiro ponteiro
        }
        delete[] v[i]; // libera o segundo ponteiro
    }
    delete[] v; // libera o primeiro ponteiro

    // liberando variáveis com zero
    nx = 0;
    ny = 0;
    nz = 0;
    r = 0; 
    g = 0;
    b = 0;
    a = 0;
}

void Sculptor::setColor(float _r, float _g, float _b, float _a)
{
    r = _r;
    g = _g;
    b = _b;
    a = _a;
}

void Sculptor::putVoxel(int x, int y, int z)
{
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
    v[x][y][z].show = true;
}

void Sculptor::cutVoxel(int x, int y, int z)
{
    v[x][y][z].show = false;
}

void Sculptor::putBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                putVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1)
{
    for (int i = x0; i <= x1; i++) {
        for (int j = y0; j <= y1; j++) {
            for (int k = z0; k <= z1; k++) {
                cutVoxel(i, j, k);
            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    // x^2 + y^2 + z^2 = r^2
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                float eq = sqrt(pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2));
                if (eq <= radius) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius)
{
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; j++) {
            for (int k = 0; k < nz; k++) {
                float eq = sqrt(pow(i - xcenter, 2) + pow(j - ycenter, 2) + pow(k - zcenter, 2));
                if (eq <= radius) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    // (x^2) / (a^2) + (y^2) / (b^2) + (z^2) / (c^2) = 1
    for(int i = xcenter - rx; i <= xcenter + rx; i++) {
        for(int j = ycenter - ry; j <= ycenter + ry; j++) {
            for(int k = zcenter - rz; k <= zcenter + rz; k++) {
                float eq = (pow(i - xcenter, 2) / pow(rx, 2)) + (pow(j - ycenter, 2) / pow(ry, 2)) + (pow(k - zcenter, 2) / pow(rz, 2));
                if (eq <= 1) {
                    putVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
{
    for(int i = xcenter - rx; i <= xcenter + rx; i++) {
        for(int j = ycenter - ry; j <= ycenter + ry; j++) {
            for(int k = zcenter - rz; k <= zcenter + rz; k++) {
                float eq = (pow(i - xcenter, 2) / pow(rx, 2)) + (pow(j - ycenter, 2) / pow(ry, 2)) + (pow(k - zcenter, 2) / pow(rz, 2));
                if (eq <= 1) {
                    cutVoxel(i, j, k);
                }
            }
        }
    }
}

void Sculptor::writeOFF(const char *filename)
{
    std::ofstream file(filename); // abre o arquivo para escrita

    // verifica se o arquivo foi aberto corretamente
    if(!file) {
        std::cerr << "Erro ao abrir o arquivo " << filename << std::endl;
        return;
    }

    // escreve o cabeçalho do formato .OFF
    file << "OFF\n";

    int sizeVoxel = 0;
    float fix = 0.5;

    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if (v[i][j][k].show) {
                    sizeVoxel++;
                }
            }
        }
    }

    // Escreve número de vértices, faces, e arestas
    file << sizeVoxel * 8 << " " << sizeVoxel * 6 << " 0" << "\n";

    // Escreve as coordenadas dos vértices
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if (v[i][j][k].show) {
                    file << i - fix << " " << j + fix << " " << k - fix << "\n"
                          << i - fix << " " << j - fix << " " << k - fix << "\n"
                          << i + fix << " " << j - fix << " " << k - fix << "\n"
                          << i + fix << " " << j + fix << " " << k - fix << "\n"
                          << i - fix << " " << j + fix << " " << k + fix << "\n"
                          << i - fix << " " << j - fix << " " << k + fix << "\n"
                          << i + fix << " " << j - fix << " " << k + fix << "\n"
                          << i + fix << " " << j + fix << " " << k + fix << "\n";
                }
            }
        }
    }

    sizeVoxel = 0;

    // Escreve as especificações das faces
    for (int i = 0; i < nx; i++) {
        for (int j = 0; j < ny; ++j) {
            for (int k = 0; k < nz; ++k) {
                if (v[i][j][k].show) {
                    int vertex = sizeVoxel * 8;

                    float colR = v[i][j][k].r;
                    float colG = v[i][j][k].g;
                    float colB = v[i][j][k].b;
                    float colA = v[i][j][k].a;

                    file << "4 " << 0 + vertex << " " << 3 + vertex << " " << 2 + vertex << " " << 1 + vertex << " " << colR << " " << colG << " " << colB << " " << colA << "\n"
                         << "4 " << 4 + vertex << " " << 5 + vertex << " " << 6 + vertex << " " << 7 + vertex << " " << colR << " " << colG << " " << colB << " " << colA << "\n"
                         << "4 " << 0 + vertex << " " << 1 + vertex << " " << 5 + vertex << " " << 4 + vertex << " " << colR << " " << colG << " " << colB << " " << colA << "\n"
                         << "4 " << 0 + vertex << " " << 4 + vertex << " " << 7 + vertex << " " << 3 + vertex << " " << colR << " " << colG << " " << colB << " " << colA << "\n"
                         << "4 " << 7 + vertex << " " << 6 + vertex << " " << 2 + vertex << " " << 3 + vertex << " " << colR << " " << colG << " " << colB << " " << colA << "\n"
                         << "4 " << 1 + vertex << " " << 2 + vertex << " " << 6 + vertex << " " << 5 + vertex << " " << colR << " " << colG << " " << colB << " " << colA << "\n";

                    sizeVoxel++;
                }
            }
        }
    }

    // Finaliza o arquivo
    file.close();

    std::cout << "Arquivo salvo com sucesso em " << filename << std::endl;
}
