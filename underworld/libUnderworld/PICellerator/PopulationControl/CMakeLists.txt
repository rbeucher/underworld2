cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/EscapedRoutine.c
    src/Finalise.c
    src/Init.c
    )

target_sources(PICellerator PRIVATE ${sources})