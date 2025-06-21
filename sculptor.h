#ifndef SCULPTOR_H
#define SCULPTOR_H

struct Voxel 
{
    float r, g, b; // Cores
    float a; // Trasnparencia
    bool show; // Incluido ou nao
};

class Sculptor 
{
    private:
        Voxel ***v; // matriz 3D
        int nx, ny, nz; // Dimensões
        float r, g, b, a; // Cor do desenho atual

    public:
        Sculptor(int _nx, int _ny, int _nz); // Construtor para iniciar as dimensões
        ~Sculptor(); // Destrutor

        // Define a cor atual de desenho
        void setColor(float r, float g, float b, float a); 

        // Ativa o voxel na posição (x,y,z) (fazendo show = true) e atribui ao mesmo a cor atual de desenho
        void putVoxel(int x, int y, int z); 

        // Desativa o voxel na posição (x,y,z) (fazendo show = false)
        void cutVoxel(int x, int y, int z);
        
        // Ativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
        void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
        
        // Desativa todos os voxels no intervalo x∈[x0,x1], y∈[y0,y1], z∈[z0,z1] e atribui aos mesmos a cor atual de desenho
        void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
        
        // Ativa todos os voxels que satisfazem à equação da esfera e atribui aos mesmos a cor atual de desenho (r,g,b,a)
        void putSphere(int xcenter, int ycenter, int zcenter, int radius);
        
        // Desativa todos os voxels que satisfazem à equação da esfera
        void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
        
        // Ativa todos os voxels que satisfazem à equação do elipsóide e atribui aos mesmos a cor atual de desenho
        void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
        
        // Desativa todos os voxels que satisfazem à equação do elipsóide
        void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
        
        // grava a escultura no formato OFF no arquivo filename
        void writeOFF(const char* filename);
};

#endif // SCULPTOR_H
