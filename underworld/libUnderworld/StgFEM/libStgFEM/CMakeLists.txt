cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/Finalise.c
    src/Init.c
    )

target_sources(StgFEM PRIVATE ${sources})

set(toolbox_sources ${toolbox_sources}
    Toolbox/Toolbox.c
)

target_sources(StgFEM_Toolboxmodule PRIVATE ${toolbox_sources})