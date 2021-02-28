# CMakeList.txt : CMake project for SRCompiler, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(INC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include")
set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib")

include_directories( ${INC_DIR} )


FILE(GLOB_RECURSE SOURCES "${SRC_DIR}/*.cpp" "${INC_DIR}/*.cpp" "${RES_DIR}/shaders/*.shader")
FILE(GLOB_RECURSE INCLUDES "${INC_DIR}/*.h" )
# Add source to this project's executable.
add_executable (SRCompiler ${SOURCES} ${INCLUDES})
if(MSVC)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
endif(MSVC)
# TODO: Add tests and install targets if needed.
