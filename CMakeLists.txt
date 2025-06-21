cmake_minimum_required(VERSION 3.16)

project(escultor3D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Faz o executável ser criado no mesmo diretório do projeto
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

# Lista completa dos arquivos do projeto
add_executable(escultor3D
    main.cpp

    sculptor.h sculptor.cpp
    figurageometrica.h figurageometrica.cpp
    putvoxel.h putvoxel.cpp
    cutvoxel.h cutvoxel.cpp
    putbox.h putbox.cpp
    cutbox.h cutbox.cpp
    putsphere.h putsphere.cpp
    cutsphere.h cutsphere.cpp
    putellipsoid.h putellipsoid.cpp
    cutellipsoid.h cutellipsoid.cpp
    readfile.h readfile.cpp
)

# Instalação padrão (opcional)
include(GNUInstallDirs)
install(TARGETS escultor3D
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Exibe mensagem durante o CMake para confirmação
message(STATUS "Executável será criado em: ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

