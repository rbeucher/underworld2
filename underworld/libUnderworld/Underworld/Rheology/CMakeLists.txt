cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/ConstitutiveMatrix.c
    src/Finalise.c
    src/Init.c
    src/ConstitutiveMatrixCartesian.cpp
    )

target_sources(Underworld PRIVATE ${sources})