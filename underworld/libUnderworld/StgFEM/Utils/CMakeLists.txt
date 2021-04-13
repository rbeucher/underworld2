cmake_minimum_required(VERSION 3.20)

set(sources ${sources}
    src/Finalise.c
    src/Init.c
    src/IrregularMeshParticleLayout.c
    src/MeshParticleLayout.c
    src/SemiLagrangianIntegrator.c
    )

target_sources(StgFEM PRIVATE ${sources})