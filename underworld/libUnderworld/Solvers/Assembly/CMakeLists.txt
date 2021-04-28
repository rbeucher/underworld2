cmake_minimum_required(VERSION 3.16)

set(sources ${sources}
    src/Finalise.c
    src/Init.c
    src/Matrix_NaiNbj.c
    src/ViscousPenaltyConstMatrixCartesian.c
    )

target_sources(Solvers PRIVATE ${sources})