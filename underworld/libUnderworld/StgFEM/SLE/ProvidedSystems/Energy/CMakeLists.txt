cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/Energy_SLE_Solver.c
    src/Finalise.c
    src/Init.c
    )

target_sources(StgFEM PRIVATE ${sources})