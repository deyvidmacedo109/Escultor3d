# Escultor 3D

Programa interativo para criação de esculturas 3D, permitindo ao usuário desenhar e manipular objetos em um ambiente virtual.

## Instruções de Desenvolvimento e Requisitos do Projeto

Este projeto consiste na criação de um programa interativo baseado na biblioteca de programação visual Qt. Ele utiliza uma classe `Sculptor` para permitir que o usuário realize desenhos e modificações em um ambiente 3D, funcionando como um "Paint 3D".

O programa foi desenvolvido com foco na usabilidade e na integração com as funcionalidades da classe `Sculptor`.

**Requisitos e Funcionalidades Exigidas:**

* **Criação de Objeto `Sculptor`:** Abstração de um objeto da classe `Sculptor` com dimensões fornecidas pelo usuário.
* **Visualização:** Permite que o usuário visualize o objeto 3D criado utilizando recursos visuais adequados.
* **Modificação de Parâmetros:** Permite ao usuário modificar parâmetros de métodos da classe `Sculptor`, como raios de esferas, dimensões de caixas (boxes) ou cores de desenho.
* **Integração de Métodos:** Agregação dos métodos especificados para a classe `Sculptor`, permitindo a seleção de cada um via botões em uma toolbox.
* **Interação com o Mouse:** Ao movimentar o mouse sobre a abstração do objeto (com o botão esquerdo pressionado), o método associado ao botão selecionado deve ser aplicado na posição correspondente na matriz 3D.
* **Salvamento de Escultura:** A interface deve prover recursos para, após o processo de desenho, permitir que o usuário salve a escultura criada em um arquivo OFF especificado.
* **Documentação Doxygen:** O programa deve ser documentado utilizando Doxygen.
* **Hospedagem no GitHub e Manual:** O programa deve ser hospedado no GitHub, e um manual de compilação e uso deve ser fornecido no arquivo `README.md`.

**Processo de Desenvolvimento:**

O projeto foi dividido em 3 etapas principais:

1.  **Parte 1:** Implementação da classe `Sculptor` e seus métodos.
2.  **Parte 2:** Aplicação de conceitos de Programação Orientada a Objetos (POO) e criação da classe abstrata `FiguraGeometrica`.
3.  **Parte 3:** Desenvolvimento visual da interface com Qt e documentação do programa.

_**Observação:** Foi exigido que o projeto faça uso do conceito de ponteiros para a criação da matriz 3D._

## Como Compilar e Usar o Escultor 3D

Para compilar e executar o Escultor 3D, siga os passos abaixo:

### Pré-requisitos

* **Qt Framework:** Certifique-se de ter o Qt instalado em seu sistema, preferencialmente a versão Qt 5 ou Qt 6. Você pode baixá-lo do [site oficial do Qt](https://www.qt.io/download).
* **Compilador C++:** Um compilador C++ (como GCC, Clang ou MSVC) compatível com seu sistema e com o Qt.
* **CMake (Opcional, mas recomendado para projetos Qt):** Para facilitar o processo de build.
* **Doxygen:** Para gerar a documentação do projeto.

### Compilação

1.  **Clone o Repositório:**
    Abra seu terminal ou prompt de comando e clone este repositório:
    ```bash
    git clone [https://github.com/deyvidmacedo109/Escultor3d.git](https://github.com/deyvidmacedo109/Escultor3d.git)
    ```
2.  **Navegue até o Diretório do Projeto:**
    ```bash
    cd Escultor3d
    ```
3.  **Configurar e Compilar com QMake (se o projeto usa .pro):**
    Se o projeto usa um arquivo `.pro` (QMake), siga:
    ```bash
    qmake seu_projeto.pro # Substitua 'seu_projeto.pro' pelo nome do seu arquivo .pro principal
    make
    # Ou, para Windows com MinGW: mingw32-make
    # Ou, para Windows com MSVC: nmake
    ```
4.  **Configurar e Compilar com CMake (se o projeto usa CMakeLists.txt):**
    Se o projeto usa um arquivo `CMakeLists.txt`, siga:
    ```bash
    mkdir build
    cd build
    cmake ..
    make
    # Ou, para Windows com Visual Studio: abra a solução .sln gerada pelo CMake
    ```
    **Observação:** Verifique se o seu projeto usa `QMake` (arquivo `.pro`) ou `CMake` (arquivo `CMakeLists.txt`).

### Uso do Programa

Após a compilação bem-sucedida, o executável será gerado. Você geralmente o encontrará na pasta de build (ou na pasta do projeto, dependendo do sistema de build).

* **Execução:**
    ```bash
    ./seu_executavel # Substitua 'seu_executavel' pelo nome do arquivo executável gerado
    ```
    Ou, em sistemas Windows, clique duas vezes no arquivo `.exe`.

    Uma vez iniciado, você poderá interagir com a interface do Escultor 3D para criar e manipular suas esculturas.

## Autores

* [Deyvid Macedo](https://github.com/deyvidmacedo109)

## Links

* [Projeto Escultor 3D - Agostinho Brito](https://agostinhobritojr.github.io/curso/progav-dca3303/escultor.html)
