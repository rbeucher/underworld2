cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/Finalise.c
    src/Init.c
    src/AugLagStokes_SLE.c
    )

target_sources(Solvers PRIVATE ${sources})