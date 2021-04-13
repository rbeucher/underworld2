cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/ConvexHull.c
    src/Finalise.c
    src/Init.c
    src/PolygonShape.c
    src/ShapeClass.c)

target_sources(StgDomain PRIVATE ${sources})