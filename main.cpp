#include "sculptor.h"
#include "readfile.h"

using namespace std;

int main() {
    // Caminho RELATIVO para o arquivo trono.txt
    ReadFile r("testeDesenhos/trono.txt");
    Sculptor *objSculptor = r.objSculptor;

    // Salva o arquivo .off no diretório do projeto
    objSculptor->writeOFF("testeDesenhos/trono.off");

    return 0;
}
