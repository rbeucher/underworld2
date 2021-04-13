cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/Finalise.c
    src/Init.c
    src/PCDVC.c
    )

target_sources(PICellerator PRIVATE ${sources})