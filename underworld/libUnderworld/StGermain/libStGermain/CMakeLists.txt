cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/Finalise.c
    src/Init.c
    src/main.c
    )

target_sources(StGermain PRIVATE ${sources})
