cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/ColourMap.c
    src/Database.c
    src/DrawingObject.c
    src/Finalise.c
    src/Init.c
    src/miniz.c
    src/sqlite3.c
    )

target_sources(gLucifer PRIVATE ${sources})
