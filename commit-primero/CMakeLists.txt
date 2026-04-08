cmake_minimum_required(VERSION 3.16)

project(commit-primero LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(commit-primero main.cpp
    LZ78.cpp
    RLE.cpp
    Rotacion.cpp
    XOR.cpp
    LZ78.h
    RLE.h
    Rotacion.h
    XOR.h
)

include(GNUInstallDirs)
install(TARGETS commit-primero
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
