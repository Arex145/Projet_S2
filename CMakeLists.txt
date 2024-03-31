cmake_minimum_required(VERSION 3.26)
project(Projet_S2 C)

set(CMAKE_C_STANDARD 23)

add_executable(Projet_S2 main.c
        deplacement_James.c
        deplacement_Jacob.h
        deplacement_Jacob.c)

target_link_libraries(Projet_S2 -lmingw32 -lalleg44)
