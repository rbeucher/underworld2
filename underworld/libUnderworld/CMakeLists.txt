cmake_minimum_required(VERSION 3.10)
cmake_policy(SET CMP0078 OLD)
cmake_policy(SET CMP0086 OLD)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
add_definitions(-DLIB_DIR="/home/romain/Projects/Project_underworld2/test/lib/python3.9/site-packages/underworld-2.11.0.dev0-py3.9-linux-x86_64.egg/underworld/lib")
add_definitions(-DMODULE_EXT=".so")

project(Underworld)
find_package(LibXml2 REQUIRED)
find_package(MPI REQUIRED)
find_package(Python3 COMPONENTS Interpreter Development NumPy)

include_directories(${Python3_INCLUDE_DIRS})
set(CMAKE_INSTALL_RPATH "$ORIGIN")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

add_compile_options(-DHAVE_LIBM)
add_compile_options(-DU_SHOW_CPLUSPLUS_API=0)
add_compile_options(-DHAVE_LIBXML2)
add_compile_options(-DHAVE_MPI)
add_compile_options(-DHAVE_PYTHON)
add_compile_options(-DHAVE_PETSC)
add_compile_options(-DHAVE_NUMPYPK)
add_compile_options(-DHAVE_MPI4PYPK)
add_compile_options(-DHAVE_H5PY)
add_compile_options(-DDEBUG)
add_compile_options(-DSWIG_PYTHON_SILENT_MEMLEAK)

add_library(pcu SHARED)
target_include_directories(pcu  PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(pcu  PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_link_libraries(pcu ${LIBXML2_LIBRARIES} MPI::MPI_C)
target_compile_definitions(pcu PRIVATE CURR_MODULE_NAME="pcu")
add_subdirectory(StGermain/pcu)

add_library(StGermain SHARED StGermain/src/main.c)
target_include_directories(StGermain PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(StGermain PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(StGermain PUBLIC ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(StGermain ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy MPI::MPI_C)
target_compile_definitions(StGermain PRIVATE CURR_MODULE_NAME="StGermain")
add_subdirectory(StGermain/Base/Foundation)
add_subdirectory(StGermain/Base/IO)
add_subdirectory(StGermain/Base/Container)
add_subdirectory(StGermain/Base/Automation)
add_subdirectory(StGermain/Base/Extensibility)
add_subdirectory(StGermain/Base/Context)
add_subdirectory(StGermain/Base)
add_subdirectory(StGermain/libStGermain)
add_subdirectory(StGermain/Utils)

add_library(StgDomain SHARED)
add_library(StgDomain_Toolboxmodule SHARED)
set_target_properties(StgDomain_Toolboxmodule PROPERTIES PREFIX "")
pkg_check_modules(PETSc PETSc)
target_include_directories(StgDomain PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(StgDomain_Toolboxmodule PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(StgDomain PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(StgDomain_Toolboxmodule PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(StgDomain PUBLIC ${Python3_NumPy_INCLUDE_DIRS})
target_include_directories(StgDomain PUBLIC ${PETSc_INCLUDE_DIRS})
target_include_directories(StgDomain_Toolboxmodule PUBLIC ${PETSc_INCLUDE_DIRS})
target_link_libraries(StgDomain ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy ${PETSC_LINK_LIBRARIES} MPI::MPI_C)
target_link_libraries(StgDomain StGermain)
target_link_libraries(StgDomain_Toolboxmodule ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy ${PETSC_LINK_LIBRARIES} MPI::MPI_C)
target_compile_definitions(StgDomain PRIVATE CURR_MODULE_NAME="StgDomain")
add_subdirectory(StgDomain/Geometry)
add_subdirectory(StgDomain/Mesh)
add_subdirectory(StgDomain/Swarm)
add_subdirectory(StgDomain/Shape)
add_subdirectory(StgDomain/Utils)
add_subdirectory(StgDomain/libStgDomain)

add_library(StgFEM SHARED)
add_library(StgFEM_Toolboxmodule SHARED)
set_target_properties(StgFEM_Toolboxmodule PROPERTIES PREFIX "")
pkg_check_modules(PETSc PETSc)
target_include_directories(StgFEM PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(StgFEM_Toolboxmodule PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(StgFEM PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(StgFEM_Toolboxmodule PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(StgFEM PUBLIC ${PETSc_INCLUDE_DIRS})
target_include_directories(StgFEM_Toolboxmodule PUBLIC ${PETSc_INCLUDE_DIRS})
target_link_libraries(StgFEM ${LIBXML2_LIBRARIES} ${PETSC_LINK_LIBRARIES} MPI::MPI_C)
target_link_libraries(StgFEM StGermain StgDomain)
target_link_libraries(StgFEM_Toolboxmodule ${LIBXML2_LIBRARIES} ${PETSC_LINK_LIBRARIES} MPI::MPI_C) 
target_compile_definitions(StgFEM PRIVATE CURR_MODULE_NAME="StgFEM")
add_subdirectory(StgFEM/Assembly)
add_subdirectory(StgFEM/Discretisation)
add_subdirectory(StgFEM/libStgFEM)
add_subdirectory(StgFEM/Utils)
add_subdirectory(StgFEM/SLE)
add_subdirectory(StgFEM/SLE/ProvidedSystems)
add_subdirectory(StgFEM/SLE/SystemSetup)
add_subdirectory(StgFEM/SLE/ProvidedSystems/Energy)
add_subdirectory(StgFEM/SLE/ProvidedSystems/StokesFlow)

add_library(PICellerator SHARED)
add_library(PICellerator_Toolboxmodule SHARED)
set_target_properties(PICellerator_Toolboxmodule PROPERTIES PREFIX "")
pkg_check_modules(PETSc PETSc)
target_compile_options(PICellerator PUBLIC "-DU_SHOW_CPLUSPLUS_API=0")
target_include_directories(PICellerator PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(PICellerator_Toolboxmodule PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(PICellerator PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(PICellerator_Toolboxmodule PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(PICellerator PUBLIC ${PETSc_INCLUDE_DIRS})
target_include_directories(PICellerator_Toolboxmodule PUBLIC ${PETSc_INCLUDE_DIRS})
target_include_directories(PICellerator PUBLIC ${Python3_NumPy_INCLUDE_DIRS})
target_include_directories(PICellerator_Toolboxmodule PUBLIC ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(PICellerator ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy ${PETSC_LINK_LIBRARIES} MPI::MPI_C) 
target_link_libraries(PICellerator StGermain StgDomain)
target_link_libraries(PICellerator_Toolboxmodule ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy ${PETSC_LINK_LIBRARIES} MPI::MPI_C) 
target_compile_definitions(PICellerator PRIVATE CURR_MODULE_NAME="PICellerator")
add_subdirectory(PICellerator/MaterialPoints)
add_subdirectory(PICellerator/PopulationControl)
add_subdirectory(PICellerator/Utils)
add_subdirectory(PICellerator/Weights)
add_subdirectory(PICellerator/libPICellerator)

add_library(Underworld SHARED)
add_library(Underworld_Toolboxmodule SHARED)
set_target_properties(Underworld_Toolboxmodule PROPERTIES PREFIX "")
pkg_check_modules(PETSc PETSc)
# The following compile option is needed because of the extern C include in 
# some of the cpp files.
# If not included, the compiler will throw a series of "template with C linkage" errors
# This seems to be related to XML
# The libXML headers are pulled in from a C header to be compiled with the C++ compiler and C++ objects
# The pb seems to be that libXML is ICU enabled and the ICU headers are detecting C++ and including the C++ standard
# library which is 99% template code.
# The solution is to pass -DU_SHOW_CPLUSPLUS_API=0 to the CXXFLAGS. 
# In the present case I chose to apply the flag to the current target (Underworld) and not pollute the
# system
target_compile_options(Underworld PUBLIC "-DU_SHOW_CPLUSPLUS_API=0")
target_include_directories(Underworld PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(Underworld_Toolboxmodule PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(Underworld PUBLIC ${PETSc_INCLUDE_DIRS})
target_include_directories(Underworld_Toolboxmodule PUBLIC ${PETSc_INCLUDE_DIRS})
target_include_directories(Underworld PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(Underworld_Toolboxmodule PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(Underworld PUBLIC ${Python3_NumPy_INCLUDE_DIRS})
target_include_directories(Underworld_Toolboxmodule PUBLIC ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(Underworld ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy ${PETSC_LINK_LIBRARIES} MPI::MPI_C) 
target_link_libraries(Underworld StgDomain StGermain PICellerator)
target_link_libraries(Underworld_Toolboxmodule ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy ${PETSC_LINK_LIBRARIES} MPI::MPI_C) 
target_compile_definitions(Underworld PRIVATE CURR_MODULE_NAME="Underworld")
add_subdirectory(Underworld/Function)
add_subdirectory(Underworld/Rheology)
add_subdirectory(Underworld/libUnderworld)
add_subdirectory(Underworld/SysTest/AnalyticPlugins)
add_subdirectory(Underworld/Utils)
add_subdirectory(Underworld/Utils/AdvectionDiffusion)


add_library(gLucifer SHARED)
add_library(gLucifer_Toolboxmodule SHARED)
set_target_properties(gLucifer_Toolboxmodule PROPERTIES PREFIX "")
pkg_check_modules(PETSc PETSc)
target_compile_options(gLucifer PUBLIC "-DU_SHOW_CPLUSPLUS_API=0")
target_include_directories(gLucifer  PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(gLucifer_Toolboxmodule PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(gLucifer  PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(gLucifer_Toolboxmodule  PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(gLucifer PUBLIC ${PETSc_INCLUDE_DIRS})
target_include_directories(gLucifer_Toolboxmodule PUBLIC ${PETSc_INCLUDE_DIRS})
target_include_directories(gLucifer PUBLIC ${Python3_NumPy_INCLUDE_DIRS})
target_include_directories(gLucifer_Toolboxmodule PUBLIC ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(gLucifer ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy ${PETSC_LINK_LIBRARIES} MPI::MPI_CXX MPI::MPI_C)  
target_link_libraries(gLucifer Underworld StGermain StgDomain PICellerator StgFEM)
target_link_libraries(gLucifer_Toolboxmodule ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy ${PETSC_LINK_LIBRARIES} MPI::MPI_CXX MPI::MPI_C)  
target_compile_definitions(gLucifer PRIVATE CURR_MODULE_NAME="gLucifer")
add_subdirectory(gLucifer/Base)
add_subdirectory(gLucifer/DrawingObjects)
add_subdirectory(gLucifer/libgLucifer)

add_library(Solvers SHARED)
add_library(Solvers_Toolboxmodule SHARED)
set_target_properties(Solvers_Toolboxmodule PROPERTIES PREFIX "")
pkg_check_modules(PETSc PETSc)
target_include_directories(Solvers PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(Solvers_Toolboxmodule PRIVATE "${PROJECT_SOURCE_DIR}")
target_include_directories(Solvers PUBLIC ${PETSc_INCLUDE_DIRS})
target_include_directories(Solvers_Toolboxmodule PUBLIC ${PETSc_INCLUDE_DIRS})
target_include_directories(Solvers PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(Solvers_Toolboxmodule PUBLIC ${LIBXML2_INCLUDE_DIR} ${MPI_C_INCLUDE_DIRS})
target_include_directories(Solvers PUBLIC ${Python3_NumPy_INCLUDE_DIRS})
target_include_directories(Solvers_Toolboxmodule PUBLIC ${Python3_NumPy_INCLUDE_DIRS})
target_link_libraries(Solvers ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy ${PETSC_LINK_LIBRARIES} MPI::MPI_C)
target_link_libraries(Solvers PICellerator Underworld StgDomain StGermain)
target_link_libraries(Solvers_Toolboxmodule ${LIBXML2_LIBRARIES} Python3::Python Python3::NumPy ${PETSC_LINK_LIBRARIES} MPI::MPI_C)
target_compile_definitions(Solvers PRIVATE CURR_MODULE_NAME="Solvers")
add_subdirectory(Solvers/Assembly)
add_subdirectory(Solvers/KSPSolvers)
add_subdirectory(Solvers/libSolvers)
add_subdirectory(Solvers/SLE)

set(target_sources
    StGermain
    StgDomain
    StgFEM
    Solvers
    Underworld
    gLucifer
    pcu
    PICellerator
    Solvers_Toolboxmodule
    gLucifer_Toolboxmodule
    Underworld_Toolboxmodule
    PICellerator_Toolboxmodule
    StgFEM_Toolboxmodule
    StgDomain_Toolboxmodule
    )

# Add install target
install(TARGETS ${target_sources}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

add_subdirectory(libUnderworldPy)