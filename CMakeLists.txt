cmake_minimum_required(VERSION 3.17)
project(Labo8_Robot)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labo8_Robot main.cpp Robot.h Robot.cpp Terrain.h Terrain.cpp saisie.cpp saisie.h Coordonnee.h)
