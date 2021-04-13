cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/DofLayout.c
    src/DomainContext.c
    src/FieldVariable.c
    src/FieldVariable_Register.c
    src/Finalise.c
    src/Init.c
    src/PETScCompatibility.c
    src/RegularMeshUtils.c
    src/SobolGenerator.c
    src/TimeIntegrand.c
    src/TimeIntegrator.c)

target_sources(StgDomain PRIVATE ${sources})